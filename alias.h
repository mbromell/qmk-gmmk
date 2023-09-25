#pragma once

#include "features/cross_os_compat.h"

enum layers {
  BASE,
  SYM,
  NUM,
  NAV,
  FUN,
  MED,
};

enum custom_keycodes {
  UPDIR = SAFE_RANGE,
  SCOPE,
  END_SCL,
  VI_SAVE,

  MY_ZIN,  // zoom in
  MY_ZOUT, // zoom out

  WORD_L,
  WORD_R,
  MY_SALL, // select all
  MY_SAVE,
  PG_TOP,  // page top
  PG_END,  // page_end
  MY_GOOG, // search selected
  MY_PTOP, // page top
  MY_UNDO,
  MY_REDO,
  MY_COPY,
  MY_PSTE, // paste
  MY_PSTP, // paste plain
  MY_FIND,
  MY_FNXT, // find next
  MY_FPRV, // find previous

  MV_FULL, // full screen window
  MV_L,    // split half left
  MV_R,    // split half right
  MV_2TL,  // split 2 thirds left
  MV_1TR,  // split 1 third right
  MV_EXIT, // quit application
  MV_XTAB, // close tab
  MV_NTAB, // next tab
  MV_PTAB, // previous tab
  SEE_ALL, // mission control
  WS_LEFT, // workspace left
  WS_RGHT, // workspace right
  WS_NEW,  // workspace new

  CA_DEL,  // ctrl + alt + delete
  CAP_SCN, // capture screen
  CAP_SEL, // capture selection of screen
};

#define XXX KC_NO
#define NO_IMPL KC_NO

#define MOD_Q ZEN_T(KC_Q)
#define MOD_W LGUI_T(KC_W)
#define MOD_E LALT_T(KC_E)
#define MOD_R LCTL_T(KC_R)
#define MOD_UND LT(NAV, KC_UNDERSCORE)
#define MOD_A LT(SYM, KC_A)
#define MOD_U LCTL_T(KC_U)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)
#define MOD_P ZEN_T(KC_P)
#define MOD_QUO LT(SYM, KC_DOUBLE_QUOTE)

// Bleeding out extra F keys for all OS's
#define MY_F1 KC_F16
#define MY_F2 KC_F17
#define MY_F3 KC_F18
#define MY_F4 KC_F19
#define MY_F5 LGUI(KC_F16)
#define MY_F6 LGUI(KC_F17)
#define MY_F7 LGUI(KC_F18)
#define MY_F8 LGUI(KC_F19)
#define MY_F9 HYPR(KC_P0)
#define MY_F10 HYPR(KC_P1)
#define MY_F11 HYPR(KC_P2)
#define MY_F12 HYPR(KC_P3)
#define MY_F13 HYPR(KC_P4)
#define MY_F14 HYPR(KC_P5)
#define MY_F15 HYPR(KC_P6)
#define MY_F16 HYPR(KC_P7)
#define MY_F17 HYPR(KC_P8)
#define MY_F18 HYPR(KC_P9)

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
