/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include "keycodes.h"
#include "keymap_us.h"
#include QMK_KEYBOARD_H

#include "os_detection.h"
#include "alias.h"
#include "features/custom_shift_keys.h"

// clang-format off
#define MINLAYOUT(k, k0, k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k40, k41, k42, k43, k44, k45, k46) \
    LAYOUT( \
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,          k, \
        k0,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, k00,              XXXXXXX, \
        k01,     k02,     k03,     k04,     k05,     k06,     k07,     k08,     k09,     k10,     k11,     k12,     k13,     k14,              XXXXXXX, \
        k15,     k16,     k17,     k18,     k19,     k20,     k21,     k22,     k23,     k24,     k25,     k26,     k27,                       XXXXXXX, \
        k28,     k29,     k30,     k31,     k32,     k33,     k34,     k35,     k36,     k37,     k38,     k39,                       XXXXXXX, XXXXXXX, \
        k40,     k41,     k42,                       k43,                                k44,     k45,     k46,              XXXXXXX, XXXXXXX, XXXXXXX)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// To put the keyboard into boot loader mode, press the key directly to the left of the rotary knob.
// To reset the keyboard, hold the traditional caps-lock key and then then press the boot loader key (key next to the rotary knob)

    [BASE] = MINLAYOUT(
        KC_MUTE,
        KC_ESC,                                                                                                              KC_BSPC,
        KC_UNDS, MOD_Q,   MOD_W,   MOD_E,   MOD_R,   KC_T,    KC_Y,    MOD_U,   MOD_I,   MOD_O,   MOD_P,   KC_COLN, KC_EQL,  KC_TAB,
        KC_LSFT, KC_A,    KC_S,    KC_D,    MOD_F,   KC_G,    KC_H,    MOD_J,   KC_K,    KC_L,    MOD_QUO, KC_RSFT, KC_ENT,
        KC_MINS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_SCLN,
        TO(FUN), TO(MED), TO(NUM),                   KC_SPC,                    NO_IMPL, NO_IMPL, TO(FUN)
    ),

    [SYM] = MINLAYOUT(
        _______,
        _______,                                                                                                             _______,
        KC_AT,   KC_DLR,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PERC, EURO,    UPDIR,   NO_IMPL, NO_IMPL, NO_IMPL, COLON_2, _______, _______,
        KC_CAPS, KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, KC_HASH, KC_LBRC, KC_PIPE, KC_AMPR, KC_TILD, KC_QUOT, _______, _______,
        _______, KC_SLSH, KC_ASTR, KC_LABK, KC_RABK, KC_CIRC, KC_RBRC, KC_BSLS, KC_GRV,  KC_EXLM, KC_QUES, END_SCL,
        XXXXXXX, XXXXXXX, _______,                   _______,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NUM] = MINLAYOUT(
        _______,
        _______,                                                                                                             _______,
        KC_UNDS, KC_DLR,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PERC, EURO,    KC_6,    KC_7,    KC_8,    KC_9,    _______, _______, _______,
        _______, KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, KC_HASH, KC_LBRC, KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,
        KC_MINS, KC_SLSH, KC_ASTR, KC_LABK, KC_RABK, KC_CIRC, KC_RBRC, KC_1,    _______, _______, PY_CALC, _______,
        XXXXXXX, XXXXXXX, _______,                   KC_0,                      XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NAV] = MINLAYOUT(
        _______,
        _______,                                                                                                             XXXXXXX,
        NO_IMPL, MY_GOOG, KC_LGUI, KC_LALT, KC_LCTL, NO_IMPL, PG_TOP,  KC_PGUP, KC_PGDN, PG_END,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, MY_SALL, MY_SAVE, MY_FPRV, MY_FIND, MY_FNXT, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, XXXXXXX, XXXXXXX,
        NO_IMPL, MY_UNDO, MY_REDO, MY_COPY, MY_PSTE, MY_PSTP, KC_HOME, WORD_L,  WORD_R,  KC_END,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX,                   _______,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [FUN] = MINLAYOUT(
        _______,
        _______,                                                                                                             SEE_ALL,
        CA_DEL,  MV_2TL,  MV_1TR,  MV_L,    MV_R,    MV_FULL, CAP_SCN, KC_F6,   KC_F7,   KC_F8,   KC_F9,   NO_IMPL, NO_IMPL, NO_IMPL,
        NO_IMPL, KC_F19,  KC_F18,  KC_F17,  KC_F16,  NO_IMPL, CAP_SEL, KC_F2,   KC_F3,   KC_F4,   KC_F5,   NO_IMPL, NO_IMPL,
        _______, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, MV_PTAB, MV_NTAB, KC_F1,   KC_F10,  KC_F11,  KC_F12,  _______,
        _______, XXXXXXX, XXXXXXX,                   KC_MEH,                    XXXXXXX, XXXXXXX, _______
    ),

    [MED] = MINLAYOUT(
        _______,
        KC_PWR,                                                                                                              NO_IMPL,
        NO_IMPL, NO_IMPL, ZOOM_I,  NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL,
        NO_IMPL, NO_IMPL, ZOOM_O,  NO_IMPL, NO_IMPL, NO_IMPL, KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT, NO_IMPL, NO_IMPL,
        NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, KC_VOLD, KC_MUTE, KC_VOLU, NO_IMPL, NO_IMPL,
        XXXXXXX, _______, XXXXXXX,                   NO_IMPL,                    XXXXXXX, XXXXXXX, XXXXXXX
    ),
};
// clang-format on


const custom_shift_key_t custom_shift_keys[] = {
    {KC_BACKSPACE, KC_DELETE},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


#define IS_MACOS detected_host_os() == OS_MACOS
#define IS_WINDOWS detected_host_os() == OS_WINDOWS
#define IS_LINUX detected_host_os() == OS_LINUX
#define IS_IOS detected_host_os() == OS_IOS
#define IS_USURE detected_host_os() == OS_UNSURE

#define NO_IMPL_CASE(message) println(strcat(message, " has not been implemented yet.")); return false;
#define OSX_CASE(kMac, kWin) tap_code16((IS_MACOS) ? kMac : kWin); return false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    if(record->event.pressed) {
        switch (keycode) {
            case MY_DQUO: tap_code16(KC_DQUO); return false;

            case UPDIR: SEND_STRING("../"); return false;
            case COLON_2: SEND_STRING("::"); return false;
            case EURO: SEND_STRING("€"); return false;
            case END_SCL: tap_code16_delay(KC_END, 10); SEND_STRING(";"); return false;
            case VI_SAVE: tap_code16_delay(KC_ESCAPE, 10); SEND_STRING(":w"); return false;

            case ZOOM_I: OSX_CASE(LCMD(KC_PLUS), LCTL(KC_PLUS));
            case ZOOM_O: OSX_CASE(LCMD(KC_MINUS), LCTL(KC_MINUS));

            case WORD_L: OSX_CASE(LOPT(KC_LEFT), LCTL(KC_LEFT));
            case WORD_R: OSX_CASE(LOPT(KC_RIGHT), LCTL(KC_RIGHT));
            case PG_TOP: OSX_CASE(LCMD(KC_DOWN), LCTL(KC_END));
            case PG_END: OSX_CASE(LCMD(KC_Z), LCTL(KC_Z));
            case MY_GOOG: NO_IMPL_CASE("MY_GOOG (Search Selected)");
            case MY_PTOP: OSX_CASE(LCMD(KC_UP), LCTL(KC_HOME));
            case MY_UNDO: OSX_CASE(LCMD(KC_Z), LCTL(KC_Z));
            case MY_REDO: OSX_CASE(LCMD(LSFT(KC_Z)), LCTL(KC_Y));
            case MY_COPY: OSX_CASE(LCMD(KC_C), LCTL(KC_INSERT));
            case MY_PSTE: OSX_CASE(LCMD(KC_V), LSFT(KC_INSERT));
            case MY_PSTP: OSX_CASE(LCMD(LSFT(LOPT(KC_V))), LCTL(LSFT(KC_V)));
            case MY_SALL: OSX_CASE(LCMD(KC_A), LCTL(KC_A));
            case MY_SAVE: OSX_CASE(LCMD(KC_S), LCTL(KC_S));
            case MY_FIND: OSX_CASE(LCMD(KC_F), LCTL(KC_F));
            case MY_FPRV: OSX_CASE(LCMD(LSFT(KC_G)), LCTL(LSFT(KC_G)));
            case MY_FNXT: OSX_CASE(LCMD(KC_G), LCTL(KC_G));

            case MV_FULL: OSX_CASE(LGUI(LCTL(KC_F)), KC_F11);
            case MV_L:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_LEFT));
                } else {
                    tap_code16_delay(LCAG(KC_0), 40);
                    tap_code16(LWIN(KC_LEFT));
                }
                return false;
            case MV_R:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_RIGHT));
                } else {
                    tap_code16_delay(LCAG(KC_0), 40);
                    tap_code16(LWIN(KC_RIGHT));
                }
                return false;
            case MV_2TL:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_G));
                } else {
                    tap_code16_delay(LCAG(KC_1), 40);
                    tap_code16(LWIN(KC_LEFT));
                }
                return false;
            case MV_1TR:
                if (IS_MACOS) {
                    tap_code16(LCA(KC_H));
                } else {
                    tap_code16_delay(LCAG(KC_1), 40);
                    tap_code16(LWIN(KC_RIGHT));
                }
                return false;
            case MV_EXIT: OSX_CASE(LCMD(KC_Q), LALT(KC_F4));
            case MV_XTAB: OSX_CASE(LCMD(KC_W), LCTL(KC_W));
            case MV_NTAB: OSX_CASE(LCMD(LSFT(KC_RBRC)), LCTL(LSFT(KC_RBRC)));
            case MV_PTAB: OSX_CASE(LCMD(LSFT(KC_LBRC)), LCTL(LSFT(KC_LBRC)));
            case SEE_ALL: OSX_CASE(KC_MISSION_CONTROL, LWIN(KC_TAB));

            case WS_LEFT: OSX_CASE(LCTL(KC_LEFT), LWIN(LCTL(KC_LEFT)));
            case WS_RGHT: OSX_CASE(LCTL(KC_RIGHT), LWIN(LCTL(KC_RIGHT)));
            case WS_NEW: OSX_CASE(KC_MISSION_CONTROL, LWIN(LCTL(KC_D)));

            case MOD_Q: OSX_CASE(LCMD_T(KC_Q), LCTL_T(KC_Q)); // If this works it's shocking!
            case MOD_P: OSX_CASE(LCMD_T(KC_P), LCTL_T(KC_P)); // If this works it's shocking!

            case CA_DEL: OSX_CASE(LCMD(LALT(KC_ESCAPE)), LCTL(LALT(KC_DELETE)));
            case CAP_SCN: OSX_CASE(LCMD(LSFT(KC_3)), KC_PRINT_SCREEN);
            case CAP_SEL: OSX_CASE(LCMD(LSFT(KC_5)), LWIN(LSFT(KC_S)));
        }
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [SYM] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [NUM] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [NAV] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [FUN] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [MED] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif
