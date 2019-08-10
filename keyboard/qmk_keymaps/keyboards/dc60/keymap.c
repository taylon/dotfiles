#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_all(
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_BSPC,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   MO(1),
      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPACE, KC_SPACE, KC_SPACE,      KC_RALT, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
      ),

  [1] = LAYOUT_all(
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_LSFT, KC_TRNS, KC_TRNS, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS
      ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

// #include QMK_KEYBOARD_H

// #include "../shared/layers.h"

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// 	[BASE] = LAYOUT_all(
//     KC_GESC, KC_1,    KC_2,      KC_3,    KC_4,    KC_5,     KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL, KC_BSPC, KC_BSPC,
//     KC_TAB,  KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,          KC_RBRC,KC_BSLS,
//     KC_CAPS, KC_A,    KC_S,      KC_D,    KC_F,    KC_G,     KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENTER,
//     KC_LSFT, KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,     KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLASH), RSFT_T(KC_SLASH), KC_UP,   KC_DELETE,
//     KC_LCTL, LM(LEDS, MOD_LGUI), KC_LALT,                   KC_SPACE, KC_SPACE, KC_SPACE,      KC_QUES, KC_PSCR,          KC_LEFT,          KC_DOWN, KC_RIGHT
//   ),

//   [LEDS] = LAYOUT_all(
//     KC_GESC, KC_1,    KC_2,      KC_3,    KC_4,    KC_5,     KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL, KC_BSPC, KC_BSPC,
//     KC_TAB,  KC_Q,    KC_W,      KC_E,    KC_R,    KC_T,     KC_Y,   RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD,          RGB_SAI, RGB_TOG,
//     KC_CAPS, KC_A,    KC_S,      KC_D,    KC_F,    KC_G,     KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENTER,
//     KC_LSFT, KC_LSFT, KC_Z,      KC_X,    KC_C,    KC_V,     KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  RSFT_T(KC_SLASH), RSFT_T(KC_SLASH), KC_UP,   KC_DELETE,
//     KC_LCTL, LM(LEDS, MOD_LGUI), KC_LALT,                   KC_SPACE, KC_SPACE, KC_SPACE,       KC_QUES, KC_PSCR,          KC_LEFT,          KC_DOWN, KC_RIGHT
//   ),

// };

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//   // MACRODOWN only works in this function
//   switch(id) {
//     case 0:
//       if (record->event.pressed) {
//         register_code(KC_RSFT);
//       } else {
//         unregister_code(KC_RSFT);
//       }
//     break;
//   }

//   return MACRO_NONE;
// }


// void matrix_init_user(void) {

// }

// void matrix_scan_user(void) {

// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   return true;
// }

// void led_set_user(uint8_t usb_led) {

// }
