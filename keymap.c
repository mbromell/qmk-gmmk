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
        KC_H,    KC_J,    KC_K,    KC_L,    MOD_DQU, MOD_SQU, KC_ENT,
        KC_N,    MOD_M,   MOD_COM, MOD_DOT, MOD_SLS, KC_RSFT,
                          MOD_VIM, NO_IMPL, NO_IMPL
    ),

    [SYM] = MINLAYOUT(
        _______, _______,
        _______, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   NO_IMPL,
        _______, KC_HASH, KC_LPRN, KC_RPRN, KC_COLN, KC_PERC,
        _______, KC_QUES, MOD_EXL, MOD_AMP, MOD_PIP, NO_IMPL,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        NO_IMPL, KC_ASTR, KC_RBRC, KC_LBRC, KC_PLUS, _______, _______, _______,
        KC_CIRC, KC_EQL,  KC_RABK, KC_LABK, KC_GRV,  _______, _______,
        NO_IMPL, MOD_MIN, MOD_TLD, MOD_BSL, MOD_SLS, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [NUM] = MINLAYOUT(
        _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    _______,
        _______, KC_0,    KC_4,    KC_5,    KC_6,    _______,
        _______, _______, KC_1,    KC_2,    KC_3,    _______,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, MOD_COM, MOD_DOT, _______, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [NAV] = MINLAYOUT(
        _______, _______,
        _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, VIM_CMD, _______,
        _______, _______, KC_LGUI, KC_LALT, KC_LCTL, _______,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        KC_HOME, KC_PGUP, KC_PGDN, KC_END,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
        KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, xxxxxxx, xxxxxxx, _______,
        _______, KC_LCTL, KC_LALT, KC_LGUI, xxxxxxx, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [FUN] = MINLAYOUT(
        _______, KC_PWR,
        xxxxxxx, KC_F12,  KC_F7,   KC_F8,   KC_F9, NO_IMPL,
        xxxxxxx, KC_F11,  KC_F4,   KC_F5,   KC_F6, NO_IMPL,
        _______, KC_F10,  KC_F1,   KC_F2,   KC_F3, NO_IMPL,
        xxxxxxx, xxxxxxx, xxxxxxx,                 _______,

        NO_IMPL, CAP_SEL, CAP_SCN, NO_IMPL, NO_IMPL, xxxxxxx, xxxxxxx, xxxxxxx,
        NO_IMPL, KC_MPRV, KC_MPLY, KC_MNXT, NO_IMPL, xxxxxxx, xxxxxxx,
        NO_IMPL, KC_MUTE, KC_VOLD, KC_VOLU, NO_IMPL, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [SYS] = MINLAYOUT(
        _______, xxxxxxx,
        xxxxxxx, NO_IMPL, NO_IMPL, KC_C11,  KC_C9,   NO_IMPL,
        xxxxxxx, KC_C8,   KC_C7,   KC_C6,   KC_C5,   NO_IMPL,
        _______, NO_IMPL, KC_LGUI, NO_IMPL, NO_IMPL, NO_IMPL,
        xxxxxxx, xxxxxxx, _______,                   _______,

        NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, xxxxxxx, xxxxxxx, xxxxxxx,
        KC_C1,   KC_C2,   KC_C3,   KC_C4,   NO_IMPL, xxxxxxx, xxxxxxx,
        NO_IMPL, KC_C10,  KC_C12,  KC_C13,  NO_IMPL, _______,
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
    {COPY, LCTL(KC_INSERT), LCMD(KC_C)},
    {CUT, LCTL(KC_X), LCMD(KC_X)},
    {PASTE, LSFT(KC_INSERT), LCMD(KC_V)},
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
    if (!process_cross_os_compat(keycode, record)) {
        return false;
    }

    // Mod tap intercepts for non-basic keycodes
    if (record->tap.count && record->event.pressed) {
        switch (keycode) {
        case MOD_DQU:
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

    // Mod hold intercepts for non-basic keycodes
    if (!record->tap.count) {
        switch (keycode) {
        case MOD_SQU:
            if (record->event.pressed) {
                layer_on(SYM);
                layer_on(NUM);
            } else {
                layer_off(NUM);
                layer_off(SYM);
            }
            return false;
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
        }
    }

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
    case MOD_SQU:
        return 170;
    case MOD_A:
        return 170;
    default:
        return TAPPING_TERM;
    }
}

/*
 * https://docs.qmk.fm/#/feature_combo
 * Key combinations (combos)
 */
const uint16_t PROGMEM caps_combo[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[] = {
    COMBO(caps_combo, KC_CAPS),
};

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
