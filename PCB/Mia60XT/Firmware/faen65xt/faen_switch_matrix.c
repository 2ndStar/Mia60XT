/* Copyright 2022 jaydenta
 */

#include "faen_switch_matrix.h"

#include "quantum.h"
#include "analog.h"
#include "atomic_util.h"
#include "print.h"

#define WAIT_DISCHARGE()
#define WAIT_CHARGE()

/* Pin and port array */
const uint32_t row_pins[]     = MATRIX_ROW_PINS;
const uint8_t  col_channels[] = MATRIX_COL_CHANNELS;
const uint32_t mux_sel_pins[] = MUX_SEL_PINS;

static ecsm_config_t config;
static uint16_t      ecsm_sw_value[MATRIX_ROWS][MATRIX_COLS];

static adc_mux adcMux;

static inline void discharge_capacitor(void) {
    writePinLow(DISCHARGE_PIN);
}
static inline void charge_capacitor(uint8_t row) {
    writePinHigh(DISCHARGE_PIN);
    writePinHigh(row_pins[row]);
}

static inline void clear_all_row_pins(void) {
    for (int row = 0; row < 6; row++) {
        writePinLow(row_pins[row]);
    }
}

static inline void init_mux_sel(void) {
    for (int idx = 0; idx < 3; idx++) {
        setPinOutput(mux_sel_pins[idx]);
    }
}

static inline void select_mux(uint8_t col) {
    uint8_t ch = col_channels[col];
    writePin(mux_sel_pins[0], ch & 1);
    writePin(mux_sel_pins[1], ch & 2);
    writePin(mux_sel_pins[2], ch & 4);
}

static inline void init_row(void) {
    for (int idx = 0; idx < 5; idx++) {
        setPinOutput(row_pins[idx]);
        writePinLow(row_pins[idx]);
    }
}

/* Initialize the peripherals pins */
int ecsm_init(ecsm_config_t const* const ecsm_config) {
    // Save config
    config = *ecsm_config;

    palSetLineMode(ANALOG_PORT, PAL_MODE_INPUT_ANALOG);
    adcMux = pinToMux(ANALOG_PORT);

    // Initialize discharge pin as discharge mode
    writePinLow(DISCHARGE_PIN);
    setPinOutputOpenDrain(DISCHARGE_PIN);

    // Initialize drive lines
    init_row();

    // Initialize multiplexer select pin
    init_mux_sel();

    // Enable AMUX
    setPinOutput(APLEX_EN_PIN_0);
    writePinLow(APLEX_EN_PIN_0);
    setPinOutput(APLEX_EN_PIN_1);
    writePinLow(APLEX_EN_PIN_1);

    return 0;
}

// Read the capacitive sensor value
static uint16_t ecsm_readkey_raw(uint8_t channel, uint8_t row, uint8_t col) {
    uint16_t sw_value = 0;

    // Select the multiplexer
    if (channel == 0) {
        writePinHigh(APLEX_EN_PIN_0);
        select_mux(col);
        writePinLow(APLEX_EN_PIN_0);
    } else {
        writePinHigh(APLEX_EN_PIN_1);
        select_mux(col);
        writePinLow(APLEX_EN_PIN_1);
    }

    // Set strobe pins to low state
    writePinLow(row_pins[row]);

    ATOMIC_BLOCK_FORCEON {
        // Set the row pin to high state and have capacitor charge
        charge_capacitor(row);

        WAIT_CHARGE();
        sw_value = adc_read(adcMux);
    }

    // Discharge peak hold capacitor
    discharge_capacitor();
    WAIT_DISCHARGE();

    return sw_value;
}

// Update press/release state of key at (row, col)
static bool ecsm_update_key(matrix_row_t* current_row, uint8_t row, uint8_t col, uint16_t sw_value) {
    bool current_state = (*current_row >> col) & 1;

    // press to release
    if (current_state && sw_value < config.low_threshold_matrix[row][col]) {
        *current_row &= ~(1 << col);
        return true;
    }

    // release to press
    if ((!current_state) && sw_value > config.high_threshold_matrix[row][col]) {
        *current_row |= (1 << col);
        return true;
    }

    return false;
}

// Scan key values and update matrix state
bool ecsm_matrix_scan(matrix_row_t current_matrix[]) {
    bool updated = false;

    // Disable AMUX of channel 1
    writePinHigh(APLEX_EN_PIN_1);
    for (int col = 0; col < sizeof(col_channels); col++) {
        for (int row = 0; row < 5; row++) {
            ecsm_sw_value[row][col] = ecsm_readkey_raw(0, row, col);
            updated |= ecsm_update_key(&current_matrix[row], row, col, ecsm_sw_value[row][col]);
        }
    }

    // Disable AMUX of channel 1
    writePinHigh(APLEX_EN_PIN_0);
    for (int col = 0; col < sizeof(col_channels); col++) {
        for (int row = 0; row < 5; row++) {
            ecsm_sw_value[row][col + 8] = ecsm_readkey_raw(1, row, col);
            updated |= ecsm_update_key(&current_matrix[row], row, col + 8, ecsm_sw_value[row][col + 8]);
        }
    }
    return updated;
}

// Debug print key values
void ecsm_print_matrix(void) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 16; col++) {
            uprintf("%4d", ecsm_sw_value[row][col]);
            if (col < 16) {
                print(",");
            }
        }
        print("\n");
    }
    print("\n");
}
