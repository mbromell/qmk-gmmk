#include "cross_os_compat.h"
#include "os_detection.h"

bool process_cross_os_compat(uint16_t keycode, keyrecord_t *record) {
  // Search for a custom shift key whose keycode is `keycode`.
  if (record->event.pressed) {
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
  }
  return true;
}
