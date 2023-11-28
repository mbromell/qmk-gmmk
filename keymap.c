/* Copyright 2023 Mark Bromell.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum.h"
#include <stdio.h>
#include QMK_KEYBOARD_H

#include "alias.h"
#include "features/cross_os_compat.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = MINLAYOUT(
        KC_MUTE, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_SCLN, MOD_A,   MOD_S,   KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    MOD_X,   MOD_C,   MOD_V,   KC_B,
        NO_IMPL, NO_IMPL, MOD_ZEL,                   MOD_SYS,

        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UNDS, KC_ESC,  KC_DEL,
        KC_H,    KC_J,    KC_K,    KC_L,    MOD_DQ,  MOD_SQ,  KC_ENT,
        KC_N,    MOD_M,   MOD_COM, MOD_DOT, MOD_SLS, KC_RSFT,
                          MOD_VIM, NO_IMPL, NO_IMPL
    ),

    [SYM] = MINLAYOUT(
        _______, _______,
        _______, KC_DLR,  KC_LCBR, KC_RCBR, /*HERE*/MOD_RBR, NO_IMPL,
        _______, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, KC_CIRC,
        _______, KC_EQL,  KC_ASTR, KC_LABK, KC_RABK, UPDIR,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        NO_IMPL, MOD_AMP, MOD_PIP, MOD_AT,  MOD_PRC, NO_IMPL, _______, NO_IMPL,
        KC_HASH, KC_RCBR, KC_LCBR, KC_SCLN, KC_BSLS, SCOPE,   _______,
        KC_QUOT, KC_TILD, KC_GRV,  KC_EXLM, KC_QUES, NO_IMPL,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [NUM] = MINLAYOUT(
        _______, _______,
        _______, MOD_DLR, MOD_SLS, MOD_LBR, MOD_RBR, NO_IMPL,
        _______, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, KC_CIRC,
        _______, KC_EQL,  KC_ASTR, KC_LABK, KC_RABK, UPDIR,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        NO_IMPL, KC_7,    KC_8,    KC_9,    KC_PERC, NO_IMPL, _______, _______,
        KC_HASH, KC_4,    KC_5,    KC_6,    KC_DOT,  _______, _______,
        KC_0,    KC_1,    KC_2,    KC_3,    KC_COMM, KC_RCTL,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [NAV] = MINLAYOUT(
        _______, _______,
        NO_IMPL, KC_LSFT, KC_LGUI, KC_LCTL, KC_LALT, NO_IMPL,
        NO_IMPL, NO_IMPL, _______, NO_IMPL, VIM_CMD, NO_IMPL,
        _______, UNDO,    REDO,    COPY,    PASTE,   PASTE_P,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        PG_TOP,  KC_PGUP, KC_PGDN, PG_END,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, xxxxxxx, xxxxxxx, _______,
        KC_HOME, WORD_L,  WORD_R,  KC_END,  xxxxxxx, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [FUN] = MINLAYOUT(
        _______, xxxxxxx,
        xxxxxxx, KC_F12,  KC_F7,   KC_F8,   KC_F9, NO_IMPL,
        xxxxxxx, KC_F11,  KC_F4,   KC_F5,   KC_F6, NO_IMPL,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3, NO_IMPL,
        xxxxxxx, xxxxxxx, xxxxxxx,                 NO_IMPL,

        NO_IMPL, CAP_SEL, CAP_SCN, NO_IMPL, NO_IMPL, xxxxxxx, xxxxxxx, xxxxxxx,
        NO_IMPL, KC_MPRV, KC_MPLY, KC_MNXT, NO_IMPL, xxxxxxx, xxxxxxx,
        NO_IMPL, KC_MUTE, KC_VOLD, KC_VOLU, NO_IMPL, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [SYS] = MINLAYOUT(
        _______, xxxxxxx,
        xxxxxxx, NO_IMPL, GF_19,   SF_18,   F_17,    NO_IMPL,
        xxxxxxx, SGF_18,  F_19,    GF_18,   GF_17,   NO_IMPL,
        xxxxxxx, NO_IMPL, SF_19,   F_18,    NO_IMPL, NO_IMPL,
        xxxxxxx, xxxxxxx, _______,                   _______,

        NO_IMPL, SGF_13,  SGF_16,  NO_IMPL, NO_IMPL, xxxxxxx, xxxxxxx, xxxxxxx,
        F_13,    F_14,    F_15,    F_16,    NO_IMPL, xxxxxxx, xxxxxxx,
        NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, xxxxxxx,
                          _______, xxxxxxx, xxxxxxx
    ),


    /*
    [] = MINLAYOUT(
        _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,

        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,
                          _______, _______, _______
    ),
    */
};

const cross_os_key_tap_t cross_os_key_tap[] = {
    {WORD_L, LCTL(KC_LEFT), LOPT(KC_LEFT)},
    {WORD_R, LCTL(KC_RIGHT), LOPT(KC_RIGHT)},
    {PG_TOP, LCTL(KC_HOME), LCMD(KC_UP)},
    {PG_END, LCTL(KC_END), LCMD(KC_DOWN)},
    {UNDO, LCTL(KC_Z), LCMD(KC_Z)},
    {REDO, LCTL(KC_Y), LCMD(LSFT(KC_Z))},
    {COPY, LCTL(KC_INSERT), LCMD(KC_C)},
    {PASTE, LSFT(KC_INSERT), LCMD(KC_V)},
    {PASTE_P, LCTL(LSFT(KC_V)), LCMD(LSFT(LOPT(KC_V)))},
    {CA_DEL, LCTL(LALT(KC_DELETE)), LCMD(LALT(KC_ESCAPE))},
    {CAP_SCN, KC_PRINT_SCREEN, LCMD(LSFT(KC_3))},
    {CAP_SEL, LWIN(LSFT(KC_S)), LCMD(LSFT(KC_5))},
};
uint8_t NUM_CROSS_OS_KEY_TAP =
    sizeof(cross_os_key_tap) / sizeof(*cross_os_key_tap);
// clang-format on

/**
 * https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
 * Custom macros to do some fancy stuff when keys are pressed, held, or raised.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    if (!process_cross_os_compat(keycode, record)) {
        return false;
    }

    // Mod tap intercepts for non-basic keycodes
    if (record->tap.count && record->event.pressed) {
        switch (keycode) {
        case MOD_DQ:
            tap_code16(KC_DOUBLE_QUOTE);
            return false;
        case MOD_EXL:
            tap_code16(KC_EXCLAIM);
            return false;
        case MOD_AMP:
            tap_code16(KC_AMPERSAND);
            return false;
        case MOD_PIP:
            tap_code16(KC_PIPE);
            return false;
        case MOD_TLD:
            tap_code16(KC_TILDE);
            return false;
        case MOD_BSL:
            tap_code16(KC_BACKSLASH);
            return false;
        case MOD_ZEL:
            // tap_code16(KC_ENTER);
            // return false;
            break;
        case MOD_VIM:
            // tap_code16(KC_TAB);
            // return false;
            break;
        }
    }

    // Mod tap intercepts for non-basic keycodes that have an extra modifier
    // if (!record->tap.count) {
    //     switch (keycode) {
    //     case MOD_ZEL:
    //         if (record->event.pressed) {
    //             register_mods(MOD_LALT);
    //         } else {
    //             unregister_mods(MOD_LALT);
    //         }
    //         return false;
    //     case MOD_VIM:
    //         if (record->event.pressed) {
    //             register_mods(MOD_LALT);
    //         } else {
    //             unregister_mods(MOD_LALT);
    //         }
    //         return false;
    //     }
    // }

    // Standard macros
    if (record->event.pressed) {
        switch (keycode) {
        case UPDIR:
            SEND_STRING("../");
            return false;
        case SCOPE:
            SEND_STRING("::");
            return false;
        case VIM_CMD:
            tap_code16(KC_ESC);
            tap_code16(KC_COLON);
            return false;
        }
    }

    return true;
}

/*
 * https://docs.qmk.fm/#/tap_hold
 * Tapping terms specific for each mod/layer tap key.
 */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MOD_QUO:
        return 170;
    case MOD_A:
        return 170;
    default:
        return TAPPING_TERM;
    }
}

// Rotary encoder config. You need to have the clockwise and counter clockwise
// specified for each layer, otherwise the code cannot compile.
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [SYM] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [NUM] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [NAV] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [FUN] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [SYS] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
#endif
