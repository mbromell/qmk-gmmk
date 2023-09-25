#pragma once

#include "keycodes.h"
#include "quantum.h"

enum cross_os_keycode_ranges {
  X_ZEN = SAFE_RANGE,
  X_ZEN_T = (X_ZEN + 0x0001),
  X_ZEN_T_MAX = (X_ZEN_T + KC_UP),
};
#undef SAFE_RANGE
#define SAFE_RANGE X_ZEN_T_MAX + 0x0001

/** Left CTRL on all OS, but Left CMD on MacOS. */
#define KC_ZEN X_ZEN
/**
 * Left CTRL mod tap on all OS, but Left CMD mod tap on MacOS.
 * `ZEN_T(kc)` can only contain up basic keys up to `KC_UP`. This is done to
 * reduce the usage of space in the QK_USER keycode range.
 */
#define ZEN_T(kc) (X_ZEN_T + kc)

/**
 * Analagous key taps across different OS. The `keycode` field is the keycode as
 * it appears your layout. The `<os>_keycode` is the `tap_code16(kc)` that will
 * be registered when `keycode` is pressed. This means that any non-custom
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
