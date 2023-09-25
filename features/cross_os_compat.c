#include "cross_os_compat.h"
#include "os_detection.h"

bool process_cross_os_compat(uint16_t keycode, keyrecord_t *record) {
  // Search for a custom shift key whose keycode is `keycode`.
  for (int i = 0; i < NUM_CROSS_OS_KEY_TAP; ++i) {
    if (keycode != cross_os_key_tap[i].keycode) {
      continue;
    }

    switch (detected_host_os()) {
    case OS_MACOS:
      tap_code16(cross_os_key_tap[i].macos_keycode);
      return false;
    default:
      tap_code16(cross_os_key_tap[i].windows_keycode);
      return false;
    }
  }

  if (keycode < KC_ZEN || keycode >= SAFE_RANGE) {
    return true;
  }

  switch (keycode) {
  case KC_ZEN:
    if (record->event.pressed) {
      register_code16(detected_host_os() == OS_MACOS ? KC_LCMD : KC_LCTL);
      return false;
    } else {
      unregister_code16(detected_host_os() == OS_MACOS ? KC_LCMD : KC_LCTL);
      return false;
    }
  case X_ZEN_T ... X_ZEN_T_MAX:
    if (record->tap.count && record->event.pressed) {
      // It's a tap, so tap the keycode.
      tap_code16(keycode - X_ZEN_T);
      return false;
    } else if (record->event.pressed) {
      // While holding down key keep modifier registered.
      register_code16(detected_host_os() == OS_MACOS ? KC_LCMD : KC_LCTL);
      return false;
    } else {
      // Unregister modifier after stopping key press.
      unregister_code16(detected_host_os() == OS_MACOS ? KC_LCMD : KC_LCTL);
      return false;
    }
    break;
  }

  return true;
}
