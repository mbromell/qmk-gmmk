#pragma once

#include "features/cross_os_compat.h"

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    FUN,
    SYS,
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
    VIM_CMD,

    CA_DEL,  // ctrl + alt + delete
    CAP_SCN, // capture screen
    CAP_SEL, // capture selection of screen
};

#define XXX KC_NO
#define xxxxxxx KC_NO
#define NO_IMPL KC_NO

// Layer BASE
#define MOD_X LGUI_T(KC_X)
#define MOD_C LALT_T(KC_C)
#define MOD_V LCTL_T(KC_V)
#define MOD_M LCTL_T(KC_M)
#define MOD_COM LALT_T(KC_COMMA)
#define MOD_DOT LGUI_T(KC_DOT)

#define MOD_A LT(NAV, KC_A)
#define MOD_S LT(SYM, KC_S)
#define MOD_DQ LT(SYM, KC_DOUBLE_QUOTE) // non-basic
#define MOD_SQ LT(SYM, KC_QUOTE)
#define MOD_SLS LT(SYM, KC_SLASH)

#define MOD_SYS LT(SYS, KC_SPACE)
#define MOD_ZEL LM(SYS, MOD_LALT)
#define MOD_VIM LM(SYS, MOD_LCTL)

// Layer SYM and NUM
#define MOD_EXL LGUI_T(KC_EXCLAIM)   // non-basic
#define MOD_AMP LALT_T(KC_AMPERSAND) // non-basic
#define MOD_PIP LCTL_T(KC_PIPE)      // non-basic
#define MOD_MIN LCTL_T(KC_MINUS)
#define MOD_TLD LALT_T(KC_TILDE)     // non-basic
#define MOD_BSL LGUI_T(KC_BACKSLASH) // non-basic

// clang-format off
// F Key stuff
#define   F_13      KC_F13
#define  SF_13 LSFT(KC_F13)
#define  GF_13 LGUI(KC_F13)
#define SGF_13  LSG(KC_F13)
#define   F_14      KC_F14
#define  SF_14 LSFT(KC_F14)
#define  GF_14 LGUI(KC_F14)
#define SGF_14  LSG(KC_F14)
#define   F_15      KC_F15
#define  SF_15 LSFT(KC_F15)
#define  GF_15 LGUI(KC_F15)
#define SGF_15  LSG(KC_F15)
#define   F_16      KC_F16
#define  SF_16 LSFT(KC_F16)
#define  GF_16 LGUI(KC_F16)
#define SGF_16  LSG(KC_F16)
#define   F_17      KC_F17
#define  SF_17 LSFT(KC_F17)
#define  GF_17 LGUI(KC_F17)
#define SGF_17  LSG(KC_F17)
#define   F_18      KC_F18
#define  SF_18 LSFT(KC_F18)
#define  GF_18 LGUI(KC_F18)
#define SGF_18  LSG(KC_F18)
#define   F_19      KC_F19
#define  SF_19 LSFT(KC_F19)
#define  GF_19 LGUI(KC_F19)
#define SGF_19  LSG(KC_F19)

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
