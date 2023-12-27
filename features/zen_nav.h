#pragma once

#include "keycodes.h"
#include "quantum.h"

/**
 *
 */
typedef struct {
    uint16_t keycode;
    uint16_t yabai_shortcut;
    uint16_t zellij_shortcut;
} zen_nav_t;

/**  */
extern const zen_nav_t zen_nav[];
/** Number of entries in the `zen_nav` table. */
extern uint8_t NUM_ZEN_NAV;

/**
 * Handler function for universal (zen) navigation of different applications.
 *
 * In keymap.c, call this function from your `process_record_user` function as
 *
 *     #include "features/zen_nav.h"
 *
 *     bool process_record_user(uint16_t keycode, keyrecord_t* record) {
 *       if (!process_zen_nav(keycode, record)) { return false; }
 *       // Your macros ...
 *
 *       return true;
 *     }
 */
bool process_zen_nav(uint16_t keycode, keyrecord_t *record);
