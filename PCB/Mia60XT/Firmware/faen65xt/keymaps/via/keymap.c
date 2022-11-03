/* Copyright 2022 jaydenta
 */

#include QMK_KEYBOARD_H

#include "faen_switch_matrix.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_all(
    /*  COL0   COL1    COL2     COL3  COL4     COL5  COL6   COL7  COL8    COL9  COL10  COL11    COL12    COL13    COL14    COL15*/
        KC_F1, KC_F2,  KC_ESC,  KC_1, KC_2,    KC_3, KC_4,  KC_5, KC_6,   KC_7, KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
        KC_F3, KC_F4,  KC_TAB,  KC_Q, KC_W,    KC_E, KC_R,  KC_T, KC_Y,   KC_U, KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_F5, KC_F6,  KC_LCTL, KC_A, KC_S,    KC_D, KC_F,  KC_G, KC_H,   KC_J, KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_GRV,  KC_ENTER,
        KC_F7, KC_F8,  KC_LSFT,       KC_Z,    KC_X, KC_C,  KC_V, KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_F9, KC_F10, KC_LWIN,       KC_LALT,       MO(2),       KC_SPC,       MO(3), KC_RWIN,          KC_RALT,          KC_RCTL),

    [1] = LAYOUT_all(
    /*  COL0   COL1    COL2     COL3  COL4     COL5  COL6   COL7  COL8    COL9  COL10  COL11    COL12    COL13    COL14    COL15*/
        KC_F1, KC_F2,  KC_ESC,  KC_1, KC_2,    KC_3, KC_4,  KC_5, KC_6,   KC_7, KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
        KC_F3, KC_F4,  KC_TAB,  KC_Q, KC_W,    KC_E, KC_R,  KC_T, KC_Y,   KC_U, KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_F5, KC_F6,  KC_LCTL, KC_A, KC_S,    KC_D, KC_F,  KC_G, KC_H,   KC_J, KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_GRV,  KC_ENTER,
        KC_F7, KC_F8,  KC_LSFT,       KC_Z,    KC_X, KC_C,  KC_V, KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_F9, KC_F10, KC_LWIN,       KC_LALT,       MO(2),       KC_SPC,       MO(3), KC_RWIN,          KC_RALT,          KC_RCTL),

    [2] = LAYOUT_all(
    /*  COL0   COL1    COL2     COL3  COL4     COL5  COL6   COL7  COL8    COL9  COL10  COL11    COL12    COL13    COL14    COL15*/
        KC_F1, KC_F2,  KC_ESC,  KC_1, KC_2,    KC_3, KC_4,  KC_5, KC_6,   KC_7, KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
        KC_F3, KC_F4,  KC_TAB,  KC_Q, KC_W,    KC_E, KC_R,  KC_T, KC_Y,   KC_U, KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_F5, KC_F6,  KC_LCTL, KC_A, KC_S,    KC_D, KC_F,  KC_G, KC_H,   KC_J, KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_GRV,  KC_ENTER,
        KC_F7, KC_F8,  KC_LSFT,       KC_Z,    KC_X, KC_C,  KC_V, KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_F9, KC_F10, KC_LWIN,       KC_LALT,       MO(2),       KC_SPC,       MO(3), KC_RWIN,          KC_RALT,          KC_RCTL),

    [3] = LAYOUT_all(
    /*  COL0   COL1    COL2     COL3  COL4     COL5  COL6   COL7  COL8    COL9  COL10  COL11    COL12    COL13    COL14    COL15*/
        KC_F1, KC_F2,  KC_ESC,  KC_1, KC_2,    KC_3, KC_4,  KC_5, KC_6,   KC_7, KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS,
        KC_F3, KC_F4,  KC_TAB,  KC_Q, KC_W,    KC_E, KC_R,  KC_T, KC_Y,   KC_U, KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
        KC_F5, KC_F6,  KC_LCTL, KC_A, KC_S,    KC_D, KC_F,  KC_G, KC_H,   KC_J, KC_K,  KC_L,    KC_SCLN, KC_QUOT, KC_GRV,  KC_ENTER,
        KC_F7, KC_F8,  KC_LSFT,       KC_Z,    KC_X, KC_C,  KC_V, KC_B,   KC_N, KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),
        KC_F9, KC_F10, KC_LWIN,       KC_LALT,       MO(2),       KC_SPC,       MO(3), KC_RWIN,          KC_RALT,          KC_RCTL)
};
