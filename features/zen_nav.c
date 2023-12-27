#include "zen_nav.h"
#include "alias.h"

bool process_zen_nav(uint16_t keycode, keyrecord_t *record) {
    // Search for a zen nav shortcut whose keycode is `keycode`.
    if (record->event.pressed) {
        for (int i = 0; i < NUM_ZEN_NAV; ++i) {
            if (keycode != zen_nav[i].keycode) {
                continue;
            }

            if (layer_state_is(YAB)) {
                tap_code16(zen_nav[i].yabai_shortcut);
                return false;
            }
            if (layer_state_is(ZEL)) {
                tap_code16(zen_nav[i].zellij_shortcut);
                return false;
            }
        }
    }
    return true;
}
