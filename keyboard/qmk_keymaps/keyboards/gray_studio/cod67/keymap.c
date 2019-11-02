#include QMK_KEYBOARD_H

#include "./shared/layers.h"
#include "./shared/tap_dance.h"
#include "./shared/custom_keys.h"

// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
// KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT(
		KC_GESC,       KC_1,    KC_2, KC_3,           KC_4, KC_5, KC_6, KC_7, KC_8,           KC_9,   KC_0,      KC_MINS,       KC_EQL,  KC_BSLS,
		KC_DEL,        KC_Q,    KC_W, LAYER_NUMPAD_F, KC_P, KC_B, KC_J, KC_L, LAYER_SYMBOL_U, KC_Y,   KC_SCOLON, KC_LBRC,       KC_RBRC, KC_BSPC,
		KC_TAB,        HM_A,    HM_R, HM_S,           KC_T, KC_G, KC_M, KC_N, HM_E,           HM_I,   HM_O,      KC_QUOTE,      KC_ENT,  KC_ENT,
		OSM(MOD_LSFT), KC_Z,    KC_X, KC_C,           KC_D, KC_V, KC_K, KC_H, KC_COMMA,       KC_DOT, KC_SLASH,  OSM(MOD_LSFT), KC_TRNS,


		KC_GESC,     APP_MUSIC, APP_TERMINAL, APP_BROWSER,    APP_EDITOR, APP_CHAT, KC_TRNS, KC_TRNS, KC_TRNS,        EDITOR_DEBUGGER, EDITOR_FILE_TREE_NAVIGATION, EDITOR_TOGGLE_FOLDING, KC_EQL,   KC_BSPC,
    KC_DEL,      KC_Q,      KC_W,         LAYER_NUMPAD_F, KC_P,       KC_B,     KC_J,    KC_L,    LAYER_SYMBOL_U, KC_Y,            KC_SCLN,                     KC_MINUS,              KC_RBRC,  KC_BSPC,
    KC_TAB,      HM_A,      HM_R,         HM_S,           HM_T,       KC_G,     KC_M,    HM_N,    HM_E,           HM_I,            HM_O,                        KC_QUOT,               KC_ENTER, KC_ENTER,
    OS_COPY_CUT, KC_Z,      KC_X,         KC_C,           KC_D,       KC_V,     KC_K,    KC_H,    KC_COMM,        KC_DOT,          KC_SLASH,                    KC_SLASH,              KC_UP,    KC_CAPSLOCK,
    OS_PASTE,    KC_TRNS,   LAYER_HUB,    KC_SPC,         KC_SPC,     KC_SPC,   KC_SPC,  KC_SPC,  KC_SPC,         GENERAL_TAB_NAV, GENERAL_TAB_RECENT,          KC_LEFT,               KC_DOWN,  KC_RGHT
  ),

  [NUMPAD] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,   KC_8,    KC_9,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,   KC_5,    KC_6,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC, KC_SPC,  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [SYMBOLS] = LAYOUT(
		KC_TRNS, KC_TRNS,   KC_TRNS,  KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PERC,   KC_AT,    SYMBOL_CBR,     KC_DLR,   KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_HASH,   KC_TILD,  SYMBOL_PRN,     KC_EQUAL, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_CIRC,   KC_EXLM,  SYMBOL_BRACKET, KC_AMPR,  KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS,
    KC_TRNS, KC_BSLASH, KC_GRAVE, KC_SPC,         KC_SPC,   KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [HUB_LAYER] = LAYOUT(
    TO(BASE), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_VAD, RGB_VAI, RGB_TOG, RGB_TOG,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUI, KC_TRNS,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RGB_SAD, RGB_HUD, RGB_SAI
  ),

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
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

void led_set_user(uint8_t usb_led) {

}
