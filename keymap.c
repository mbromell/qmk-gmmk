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
#include "features/custom_shift_keys.h"
#include "features/cross_os_compat.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = MINLAYOUT(
    KC_MUTE, KC_BSPC,
    KC_MINS, MOD_Q,   MOD_W,   MOD_E,   MOD_R,   KC_T,
    MOD_UND, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    MOD_V,   KC_B,
    MO(FUN), MO(MED), MO(NUM),                   KC_SPC,

    KC_Y,    MOD_U,   MOD_I,   MOD_O,   MOD_P,   KC_SCLN, KC_EQL,  KC_TAB,
    KC_H,    KC_J,    KC_K,    KC_L,    KC_DQUO, KC_COLN, KC_ENT,
    KC_N,    MOD_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                      NO_IMPL, NO_IMPL, MO(FUN)
  ),

  [SYM] = MINLAYOUT(
    _______, _______,
    KC_AT,   KC_DLR,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PERC,
    _______, KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, KC_HASH,
    KC_CAPS, KC_SLSH, KC_ASTR, KC_LABK, KC_RABK, KC_CIRC,
    XXXXXXX, XXXXXXX, _______,                   _______,

    NO_IMPL, UPDIR,   NO_IMPL, NO_IMPL, NO_IMPL, END_SCL, _______, _______,
    KC_LBRC, KC_PIPE, KC_AMPR, KC_TILD, KC_QUOT, SCOPE,   _______,
    KC_RBRC, KC_BSLS, KC_GRV,  KC_EXLM, KC_QUES, _______,
                      XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [NUM] = MINLAYOUT(
    _______, _______,
    KC_MINS, KC_DLR,  KC_PLUS, KC_LCBR, KC_RCBR, KC_PERC,
    _______, KC_EQL,  KC_MINS, KC_LPRN, KC_RPRN, KC_HASH,
    _______, KC_SLSH, KC_ASTR, KC_LABK, KC_RABK, KC_CIRC,
    XXXXXXX, XXXXXXX, _______,                   KC_0,

    NO_IMPL, KC_6,    KC_7,    KC_8,    KC_9,    _______, _______, _______,
    KC_LBRC, KC_2,    KC_3,    KC_4,    KC_5,    _______, _______,
    KC_RBRC, KC_1,    _______, _______, MY_F18,  _______,
                      XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [NAV] = MINLAYOUT(
    _______, XXXXXXX,
    NO_IMPL, MY_GOOG, KC_LGUI, KC_LALT, KC_LCTL, NO_IMPL,
    _______, MY_SALL, MY_SAVE, MY_FPRV, MY_FIND, MY_FNXT,
    _______, MY_UNDO, MY_REDO, MY_COPY, MY_PSTE, MY_PSTP,
    XXXXXXX, XXXXXXX, XXXXXXX,                   _______,

    PG_TOP,  KC_PGUP, KC_PGDN, PG_END,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_HOME, KC_WRDL, KC_WRDR, KC_END,  XXXXXXX, XXXXXXX,
                      XXXXXXX, XXXXXXX, XXXXXXX
  ),

  [FUN] = MINLAYOUT(
    _______, SEE_ALL,
    CA_DEL,  MV_2TL,  MV_1TR,  MV_L,    MV_R,    MV_FULL,
    NO_IMPL, MY_F4,   MY_F3,   MY_F2,   MY_F1,   NO_IMPL,
    _______, MY_F8,   MY_F7,   MY_F6,   MY_F5,   MV_PTAB,
    _______, XXXXXXX, XXXXXXX,                   KC_MEH,

    CAP_SCN, KC_F6,   KC_F7,   KC_F8,   KC_F9,   NO_IMPL, NO_IMPL, NO_IMPL,
    CAP_SEL, KC_F2,   KC_F3,   KC_F4,   KC_F5,   NO_IMPL, NO_IMPL,
    MV_NTAB, KC_F1,   KC_F10,  KC_F11,  KC_F12,  _______,
                      XXXXXXX, XXXXXXX, _______
  ),

  [MED] = MINLAYOUT(
    _______, NO_IMPL,
    NO_IMPL, NO_IMPL, ZOOM_I,  NO_IMPL, NO_IMPL, NO_IMPL,
    NO_IMPL, NO_IMPL, ZOOM_O,  NO_IMPL, NO_IMPL, NO_IMPL,
    NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL,
    XXXXXXX, _______, XXXXXXX,                   NO_IMPL,

    NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, NO_IMPL, KC_PWR, NO_IMPL,
    KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT, NO_IMPL, NO_IMPL,
    NO_IMPL, KC_VOLD, KC_MUTE, KC_VOLU, NO_IMPL, NO_IMPL,
                      XXXXXXX, XXXXXXX, XXXXXXX
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
    {MY_ZIN,  LCTL(KC_PLUS),          LCMD(KC_PLUS)},
    {MY_ZOUT, LCTL(KC_MINUS),         LCMD(KC_MINUS)},
    {WORD_L,  LCTL(KC_LEFT),          LOPT(KC_LEFT)},
    {WORD_R,  LCTL(KC_RIGHT),         LOPT(KC_RIGHT)},
    {PG_TOP,  LCTL(KC_HOME),          LCMD(KC_UP)},
    {PG_END,  LCTL(KC_END),           LCMD(KC_DOWN)},
    {MY_SALL, LCTL(KC_A),             LCMD(KC_A)},
    {MY_SAVE, LCTL(KC_S),             LCMD(KC_S)},
    {MY_PTOP, LCTL(KC_HOME),          LCMD(KC_UP)},
    {MY_REDO, LCTL(KC_Y),             LCMD(LSFT(KC_Z))},
    {MY_COPY, LCTL(KC_INSERT),        LCMD(KC_C)},
    {MY_PSTE, LSFT(KC_INSERT),        LCMD(KC_V)},
    {MY_PSTP, LCTL(LSFT(KC_V)),       LCMD(LSFT(LOPT(KC_V)))},
    {MY_FPRV, LCTL(LSFT(KC_G)),       LCMD(LSFT(KC_G))},
    {MY_FNXT, LCTL(KC_G),             LCMD(KC_G)},
    {MV_FULL, KC_F11,                 LGUI(LCTL(KC_F))},
    {MV_EXIT, LALT(KC_F4),            LCMD(KC_Q)},
    {MV_L,    KC_NO,                  LCA(KC_LEFT)},
    {MV_R,    KC_NO,                  LCA(KC_RIGHT)},
    {MV_2TL,  KC_NO,                  LCA(KC_G)},
    {MV_1TR,  KC_NO,                  LCA(KC_H)},
    {MV_XTAB, LCTL(KC_W),             LCMD(KC_W)},
    {MV_NTAB, LCTL(LSFT(KC_RBRC)),    LCMD(LSFT(KC_RBRC))},
    {MV_PTAB, LCTL(LSFT(KC_LBRC)),    LCMD(LSFT(KC_LBRC))},
    {SEE_ALL, LWIN(KC_TAB),           KC_MISSION_CONTROL},
    {WS_LEFT, LWIN(LCTL(KC_LEFT)),    LCTL(KC_LEFT)},
    {WS_RGHT, LWIN(LCTL(KC_RIGHT)),   LCTL(KC_RIGHT)},
    {WS_NEW,  LWIN(LCTL(KC_D)),       KC_MISSION_CONTROL},
    {CA_DEL,  LCTL(LALT(KC_DELETE)),  LCMD(LALT(KC_ESCAPE))},
    {CAP_SCN, KC_PRINT_SCREEN,        LCMD(LSFT(KC_3))},
    {CAP_SEL, LWIN(LSFT(KC_S)),       LCMD(LSFT(KC_5))},
};
uint8_t NUM_CROSS_OS_KEY_TAP =
    sizeof(cross_os_key_tap) / sizeof(*cross_os_key_tap);
// clang-format on

// https://docs.qmk.fm/#/feature_macros?id=using-macros-in-c-keymaps
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
    case MOD_UND:
      tap_code16(KC_UNDERSCORE);
      return false;
    case MOD_QUO:
      tap_code16(KC_DOUBLE_QUOTE);
      return false;
    }
  }

  if (record->event.pressed) {
    switch (keycode) {
    case UPDIR:
      SEND_STRING("../");
      return false;
    case SCOPE:
      SEND_STRING("::");
      return false;
    case END_SCL:
      tap_code16_delay(KC_END, 10);
      SEND_STRING(";");
      return false;
    case VI_SAVE:
      tap_code16_delay(KC_ESCAPE, 10);
      SEND_STRING(":w");
      return false;
    }
  }
  return true;
}

// https://docs.qmk.fm/#/tap_hold
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [SYM] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [NUM] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [NAV] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [FUN] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
    [MED] = {ENCODER_CCW_CW(KC_TRNS, KC_TRNS)},
};
#endif
