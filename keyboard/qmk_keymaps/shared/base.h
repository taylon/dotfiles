#include "layers.h"
#include "tap_dance.h"
#include "keylogger.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  VRSN,
};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  log_keyaction(keycode, record);

  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }

      return false;
      break;
  }

  return true;
}
