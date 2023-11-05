#pragma once

#include "features/cross_os_compat.h"

enum layers {
  BASE,
  SYM,
  NUM,
  NAV,
  FUN,
};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  SCOPE,

  WORD_L,
  WORD_R,
  PG_TOP,
  PG_END,
  UNDO,
  REDO,
  COPY,
  PASTE,
  PASTE_P,

  CA_DEL,  // ctrl + alt + delete
  CAP_SCN, // capture screen
  CAP_SEL, // capture selection of screen
};

#define XXX KC_NO
#define NO_IMPL KC_NO

#define MOD_SPC LT(NUM, KC_SPC)
#define MOD_Q LSFT_T(KC_Q)
#define MOD_W LGUI_T(KC_W)
#define MOD_E LALT_T(KC_E)
#define MOD_R LCTL_T(KC_R)
#define MOD_A LT(SYM, KC_A)
#define MOD_S LT(NAV, KC_S)
#define MOD_U LCTL_T(KC_U)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)
#define MOD_P LSFT_T(KC_P)
#define MOD_QUO LT(SYM, KC_DOUBLE_QUOTE)

// clang-format off
#define MINLAYOUT(nob,k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k10,k11,k12,k13, \
    k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,k30, \
    k31,k32,k33,k34,k35,k36,k37,k38,k39,k40,k41,k42,k43,k44,k45,k46) \
  LAYOUT( \
    XXX,XXX,XXX,XXX,XXX,XXX,    XXX,XXX,XXX,XXX,XXX,XXX,XXX,QK_BOOT,nob, \
    XXX,XXX,XXX,XXX,XXX,XXX,    XXX,XXX,XXX,XXX,XXX,XXX,XXX,k00,XXX, \
    k01,k02,k03,k04,k05,k06,    k23,k24,k25,k26,k27,k28,k29,k30,XXX, \
    k07,k08,k09,k10,k11,k12,    k31,k32,k33,k34,k35,k36,k37,    XXX, \
    k13,k14,k15,k16,k17,k18,    k38,k39,k40,k41,k42,k43,    XXX,XXX, \
    k19,k20,k21,        k22,            k44,k45,k46,    XXX,XXX,XXX)
// clang-format on
