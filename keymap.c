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
#include "features/zen_nav.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = MINLAYOUT(
        KC_MUTE, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_SCLN, MOD_A,   MOD_S,   KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    MOD_X,   MOD_C,   MOD_V,   KC_B,
        NO_IMPL, NO_IMPL, MO(ZEL),                   MOD_YAB,

        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_UNDS, KC_ESC,  KC_DEL,
        KC_H,    KC_J,    KC_K,    KC_L,    MOD_DQU, MOD_SQU, KC_ENT,
        KC_N,    MOD_M,   MOD_COM, MOD_DOT, MOD_SLS, KC_RSFT,
                          MO(ZEL), NO_IMPL, NO_IMPL
    ),

    [SYM] = MINLAYOUT(
        _______, _______,
        _______, KC_DLR,  KC_LCBR, KC_RCBR, KC_AT,   NO_IMPL,
        _______, KC_HASH, KC_LPRN, KC_RPRN, KC_COLN, KC_PERC,
        _______, KC_QUES, MOD_EXL, MOD_AMP, MOD_PIP, UPDIR,
        xxxxxxx, xxxxxxx, xxxxxxx,                   _______,

        NO_IMPL, KC_ASTR, KC_RBRC, KC_LBRC, KC_PLUS, _______, _______, _______,
        KC_CIRC, KC_EQL,  KC_RABK, KC_LABK, KC_GRV,  _______, _______,
        WALRUS,  MOD_MIN, MOD_TLD, MOD_BSL, MOD_SLS, _______,
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
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx, xxxxxxx, _______,
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
        NO_IMPL, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                          xxxxxxx, xxxxxxx, xxxxxxx
    ),

    // Just copy paste each layer, keep it simple don't over engineer to comply
    // with DRY..
    [YAB] = MINLAYOUT(
        _______, _______,
        _______, WIN_CLS, TAB_CLS, WIN_EQU, WIN_ROT, TAB_NEW,
        _______, TAB_1,   TAB_2,   TAB_3,   TAB_4,   _______,
        _______, _______, _______, _______, WIN_SPL, _______,
        _______, _______, _______,                   _______,

        _______, TAB_MVL, TAB_MVR, SES_MAN, _______, _______, _______, _______,
        FOC_H,   FOC_J,   FOC_K,   FOC_L,   _______, _______, _______,
        WIN_NEW, WIN_MAX, WIN_FLT, _______, _______, _______,
                          _______, _______, _______
    ),
    [ZEL] = MINLAYOUT(
        _______, _______,
        _______, WIN_CLS, TAB_CLS, WIN_EQU, WIN_ROT, TAB_NEW,
        _______, TAB_1,   TAB_2,   TAB_3,   TAB_4,   _______,
        _______, _______, _______, _______, WIN_SPL, _______,
        _______, _______, _______,                   _______,

        _______, TAB_MVL, TAB_MVR, SES_MAN, _______, _______, _______, _______,
        FOC_H,   FOC_J,   FOC_K,   FOC_L,   _______, _______, _______,
        WIN_NEW, WIN_MAX, WIN_FLT, _______, _______, _______,
                          _______, _______, _______
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
    {WORD_L,    C(KC_LEFT),         A(KC_LEFT)},
    {WORD_R,    C(KC_RIGHT),        A(KC_RIGHT)},
    {UNDO,      C(KC_Z),            G(KC_Z)},
    {COPY,      C(KC_INSERT),       G(KC_C)},
    {CUT,       C(KC_X),            G(KC_X)},
    {PASTE,     S(KC_INSERT),       G(KC_V)},
    {CAP_SCN,   KC_PRINT_SCREEN,    G(S(KC_3))},
    {CAP_SEL,   G(S(KC_S)),         G(S(KC_5))},
};
uint8_t NUM_CROSS_OS_KEY_TAP = sizeof(cross_os_key_tap) / sizeof(*cross_os_key_tap);

const zen_nav_t zen_nav[] = {
    {FOC_H,     C(KC_F13),          A(KC_LEFT)},
    {FOC_J,     C(KC_F14),          A(KC_DOWN)},
    {FOC_K,     C(KC_F15),          A(KC_UP)},
    {FOC_L,     C(KC_F16),          A(KC_RIGHT)},
    {TAB_1,     C(S(G(KC_F13))),    A(KC_COMMA)},
    {TAB_2,     C(S(G(KC_F14))),    A(KC_DOT)},
    {TAB_3,     C(S(G(KC_F15))),    A(KC_SLASH)},
    {TAB_4,     C(S(G(KC_F16))),    A(KC_SEMICOLON)},
    {WIN_ROT,   C(KC_F17),          A(KC_RIGHT_BRACKET)},
    {WIN_MAX,   C(G(KC_F17)),       A(S(KC_MINUS))},
    {WIN_EQU,   C(S(G(KC_F17))),    NO_IMPL},
    {WIN_FLT,   C(KC_F18),          A(KC_BACKSLASH)},
    {WIN_SPL,   C(S(KC_F18)),       NO_IMPL},
    {WIN_NEW,   NO_IMPL,            A(KC_QUOTE)},
    {WIN_CLS,   G(KC_Q),            A(S(KC_GRAVE))},
    {TAB_NEW,   NO_IMPL,            A(S(KC_BACKSLASH))},
    {TAB_CLS,   NO_IMPL,            A(KC_GRAVE)},
    {TAB_MVR,   NO_IMPL,            A(S(KC_SLASH))},
    {TAB_MVL,   NO_IMPL,            A(S(KC_SEMICOLON))},
    {SES_MAN,   C(KC_UP),           A(S(KC_9))},
};
uint8_t NUM_ZEN_NAV = sizeof(zen_nav) / sizeof(*zen_nav);
// clang-format on

/**
 * https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
 * Custom macros to do some fancy stuff when keys are pressed, held, or raised.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_cross_os_compat(keycode, record)) {
        return false;
    }
    if (!process_zen_nav(keycode, record)) {
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
        // case MOD_ZEL:
        //     tap_code16(KC_ENTER);
        //     return false;
        //     break;
        // case MOD_VIM:
        //     tap_code16(KC_TAB);
        //     return false;
        //     break;
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
        case WALRUS:
            SEND_STRING(":=");
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
    [YAB] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [ZEL] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
#endif
