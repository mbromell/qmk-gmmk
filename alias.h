#pragma once

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    FUN,
    MED,
};

enum custom_keycodes {
    MY_DEBG = SAFE_RANGE,

    UPDIR,      // ../
    COLON_2,    // ::
    END_SCL,    // end semi-colon
    VI_SAVE,    // :w

    ZOOM_I,     // zoom in
    ZOOM_O,     // zoom out

    WORD_L,     // word left
    WORD_R,     // word right
    PG_TOP,     // page top
    PG_END,     // page_end
    MY_GOOG,    // search selected
    MY_PTOP,    // page top
    MY_UNDO,
    MY_REDO,
    MY_COPY,
    MY_PSTE,    // paste
    MY_PSTP,    // paste plain
    MY_SALL,    // select all
    MY_SAVE,
    MY_FIND,
    MY_FPRV,    // find previous
    MY_FNXT,    // find next

    MV_FULL,    // full screen window
    MV_L,       // split half left
    MV_R,       // split half right
    MV_2TL,     // split 2 thirds left
    MV_1TR,     // split 1 third right
    MV_EXIT,    // quit application
    MV_XTAB,    // close tab
    MV_NTAB,    // next tab
    MV_PTAB,    // previous tab
    SEE_ALL,    // mission control
    WS_LEFT,    // workspace left
    WS_RGHT,    // workspace right
    WS_NEW,     // workspace new

    CA_DEL,
    CAP_SCN,    // capture screen
    CAP_SEL,    // capture selection of screen
};

#define NO_IMPL KC_NO

// KEYPAD OVERRIDE MACROS
#define PY_CALC HYPR(KC_P0)

#define MOD_Q LCMD_T(KC_Q)
#define MOD_W LGUI_T(KC_W)
#define MOD_E LALT_T(KC_E)
#define MOD_R LCTL_T(KC_R)
#define MOD_V LT(SYM, KC_V)

#define MOD_P LCMD_T(KC_P)
#define MOD_U LCTL_T(KC_U)
#define MOD_I LALT_T(KC_I)
#define MOD_O LGUI_T(KC_O)
#define MOD_M LT(SYM, KC_M)
#define MOD_UND LT(NAV, KC_UNDERSCORE)
