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
#include <stdio.h>
#include QMK_KEYBOARD_H

#include "alias.h"
#include "features/cross_os_compat.h"
#include "features/custom_shift_keys.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = MINLAYOUT(
    KC_MUTE, KC_BSPC,
    KC_MINS, MOD_Q,   MOD_W,   MOD_E,   MOD_R,   KC_T,
    KC_UNDS, MOD_A,   MOD_S,   KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
    NO_IMPL, NO_IMPL, MO(FUN),                   MOD_SPC,

    KC_Y,    MOD_U,   MOD_I,   MOD_O,   MOD_P,   KC_EQL,  KC_ESC,  KC_TAB,
    KC_H,    KC_J,    KC_K,    KC_L,    MOD_QUO, KC_COLN, KC_ENT,
    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    MO(FUN), NO_IMPL, NO_IMPL
  ),

  [SYM] = MINLAYOUT(
    _______, _______,
    KC_ZEN,  KC_DLR,  KC_SLSH, KC_LBRC, KC_RBRC, MD_CODE,
    KC_CAPS, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, KC_CIRC,
    KC_LCTL, KC_EQL,  KC_ASTR, KC_LABK, KC_RABK, UPDIR,
    XXXXXXX, XXXXXXX, _______,                   _______,

    MLN_STR, KC_AMPR, KC_PIPE, KC_AT,   KC_PERC, KC_ZEN,  _______, END_SCL,
    KC_HASH, KC_RCBR, KC_LCBR, KC_SCLN, KC_BSLS, SCOPE,   _______,
    KC_QUOT, KC_TILD, KC_GRV,  KC_EXLM, KC_QUES, KC_RCTL,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [NUM] = MINLAYOUT(
    _______, _______,
    KC_ZEN,  KC_DLR,  KC_SLSH, KC_LBRC, KC_RBRC, MD_CODE,
    KC_CAPS, KC_PLUS, KC_MINS, KC_LPRN, KC_RPRN, KC_CIRC,
    KC_LCTL, KC_EQL,  KC_ASTR, KC_LABK, KC_RABK, UPDIR,
    XXXXXXX, XXXXXXX, _______,                   _______,

    NO_IMPL, KC_7,    KC_8,    KC_9,    KC_PERC, KC_ZEN,  _______, _______,
    KC_HASH, KC_4,    KC_5,    KC_6,    KC_DOT,  KC_COLN, _______,
    KC_0,    KC_1,    KC_2,    KC_3,    KC_COMM, KC_RCTL,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [NAV] = MINLAYOUT(
    _______, XXXXXXX,
    NO_IMPL, KC_ZEN,  KC_LGUI, KC_LALT, KC_LCTL, NO_IMPL,
    _______, , , , MY_FIND, MY_FNXT,
    _______, MY_UNDO, MY_REDO, MY_COPY, PASTE,   PASTE_P,
    XXXXXXX, XXXXXXX, XXXXXXX,                   _______,

    PG_TOP,  KC_PGUP, KC_PGDN, PG_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_HOME, WORD_L,  WORD_R,  KC_END,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [FUN] = MINLAYOUT(
    _______, SEE_ALL,
    CA_DEL,  NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL,
    KC_CAPS, KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT,
    KC_PWR,  NO_IMPL, KC_MUTE, KC_VOLD, KC_VOLD, NO_IMPL,
    _______, XXXXXXX, XXXXXXX,                   NO_IMPL,

    CAP_SCN, KC_F7,   KC_F8,   KC_F9,   KC_F12,  NO_IMPL, NO_IMPL, NO_IMPL,
    CAP_SEL, KC_F4,   KC_F5,   KC_F6,   KC_F11,  NO_IMPL, NO_IMPL,
    NO_IMPL, KC_F1,   KC_F2,   KC_F3,   KC_F10,  _______,
    XXXXXXX, XXXXXXX, _______
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

const custom_shift_key_t custom_shift_keys[] = {
    {KC_BACKSPACE, KC_DELETE},
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(*custom_shift_keys);

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
    case MOD_QUO:
      tap_code16(KC_DOUBLE_QUOTE);
      return false;
    }
  }

  // The rest of the macros
  if (record->event.pressed) {
    switch (keycode) {
    case UPDIR:
      SEND_STRING("../");
      return false;
    case SCOPE:
      SEND_STRING("::");
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
};
#endif
