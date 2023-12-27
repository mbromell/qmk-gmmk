#pragma once

#include "features/cross_os_compat.h"

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    FUN,
    SYS,

    YAB,
    ZEL,
};

enum custom_keycodes {
    UPDIR = SAFE_RANGE,
    SCOPE,
    WALRUS,

    WORD_L,
    WORD_R,
    UNDO,
    COPY,
    CUT,
    PASTE,
    VIM_CMD,

    CAP_SCN, // capture screen
    CAP_SEL, // capture selection of screen

    FOC_H,
    FOC_J,
    FOC_K,
    FOC_L,
    TAB_1,
    TAB_2,
    TAB_3,
    TAB_4,
    WIN_ROT,
    WIN_MAX,
    WIN_EQU,
    WIN_FLT,
    WIN_SPL,
    WIN_NEW,
    WIN_CLS,
    TAB_NEW,
    TAB_CLS,
    TAB_MVR,
    TAB_MVL,
    SES_MAN,
};

#define xxxxxxx KC_NO
#define NO_IMPL KC_NO

// Layer BASE
#define MOD_X LGUI_T(KC_X)
#define MOD_C LALT_T(KC_C)
#define MOD_V LCTL_T(KC_V)
#define MOD_M LCTL_T(KC_M)
#define MOD_COM LALT_T(KC_COMMA)
#define MOD_DOT LGUI_T(KC_DOT)

#define MOD_A LT(SYM, KC_A)
#define MOD_S LT(NAV, KC_S)
#define MOD_DQU LT(SYM, KC_DOUBLE_QUOTE) // non-basic
#define MOD_SQU LT(NUM, KC_QUOTE)
#define MOD_SLS LT(SYM, KC_SLASH)

#define MOD_YAB LT(YAB, KC_SPACE)
#define MOD_ZEL LT(ZEL, MOD_LALT)

// Layer SYM and NUM
#define MOD_EXL LGUI_T(KC_EXCLAIM)   // non-basic
#define MOD_AMP LALT_T(KC_AMPERSAND) // non-basic
#define MOD_PIP LCTL_T(KC_PIPE)      // non-basic
#define MOD_MIN LCTL_T(KC_MINUS)
#define MOD_TLD LALT_T(KC_TILDE)     // non-basic
#define MOD_BSL LGUI_T(KC_BACKSLASH) // non-basic

// clang-format off
// Custom keys for window manager
#define KC_C1        KC_F13
#define KC_C2        KC_F14
#define KC_C3        KC_F15
#define KC_C4        KC_F16
#define KC_C5    LSG(KC_F13)
#define KC_C6    LSG(KC_F14)
#define KC_C7    LSG(KC_F15)
#define KC_C8    LSG(KC_F16)
#define KC_C9        KC_F17
#define KC_C10  LGUI(KC_F17)
#define KC_C11   LSG(KC_F17)
#define KC_C12       KC_F18
#define KC_C13  LSFT(KC_F18)
#define KC_C14       NO_IMPL
#define KC_C15  LGUI(KC_Q)
#define KC_C16       NO_IMPL
#define KC_C17       NO_IMPL
#define KC_C18       NO_IMPL
#define KC_C19       NO_IMPL
#define KC_C20  LCTL(KC_UP)

#define xxx KC_NO
#define MINLAYOUT(nob,k00,k01,k02,k03,k04,k05,k06,k07,k08,k09,k10,k11,k12,k13, \
        k14,k15,k16,k17,k18,k19,k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,k30, \
        k31,k32,k33,k34,k35,k36,k37,k38,k39,k40,k41,k42,k43,k44,k45,k46) \
    LAYOUT( \
        xxx,xxx,xxx,xxx,xxx,xxx,    xxx,xxx,xxx,xxx,xxx,xxx,xxx,QK_BOOT,nob, \
        xxx,xxx,xxx,xxx,xxx,xxx,    xxx,xxx,xxx,xxx,xxx,xxx,xxx,k00,xxx, \
        k01,k02,k03,k04,k05,k06,    k23,k24,k25,k26,k27,k28,k29,k30,xxx, \
        k07,k08,k09,k10,k11,k12,    k31,k32,k33,k34,k35,k36,k37,    xxx, \
        k13,k14,k15,k16,k17,k18,    k38,k39,k40,k41,k42,k43,    xxx,xxx, \
        k19,k20,k21,        k22,            k44,k45,k46,    xxx,xxx,xxx)
// clang-format on
