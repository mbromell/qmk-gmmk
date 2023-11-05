#pragma once

#include "keycodes.h"
#include "quantum.h"

/**
 * Analagous key taps across different OS. The `keycode` field is the keycode as
 * it appears in your layout. The `<os>_keycode` is the `tap_code16(kc)` that
 * will be registered when `keycode` is pressed. This means that any non-custom
 * keycodes will be overridden by this feature.
 */
typedef struct {
  uint16_t keycode;
  uint16_t windows_keycode;
  uint16_t macos_keycode;
} cross_os_key_tap_t;

/** Table of keycodes that differ between OS. */
extern const cross_os_key_tap_t cross_os_key_tap[];
/** Number of entries in the `cross_os_key_tap` table. */
extern uint8_t NUM_CROSS_OS_KEY_TAP;

/**
 * Handler function for `cross_os_key_tap` and `ZEN_T` keys.
 *
 * In keymap.c, call this function from your `process_record_user` function as
 *
 *     #include "features/cross_os_compat.h"
 *
 *     bool process_record_user(uint16_t keycode, keyrecord_t* record) {
 *       if (!process_cross_os_compat(keycode, record)) { return false; }
 *       // Your macros ...
 *
 *       return true;
 *     }
 */
bool process_cross_os_compat(uint16_t keycode, keyrecord_t *record);
