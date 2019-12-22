#include QMK_KEYBOARD_H

#include "../../shared/base.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // StarCraft 2
  [BASE] = LAYOUT(
    // Left hand
    KC_1, KC_2, KC_7, KC_4, KC_5, KC_6,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_P, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_O, KC_Z, KC_X, KC_C, KC_V, KC_B,
    KC_I, KC_U, KC_Y, KC_L, KC_K,

    KC_SPACE, KC_F10,
    KC_TRANSPARENT,
    OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRANSPARENT
  ),

};

// void matrix_init_user(void) {

// }

// void matrix_scan_user(void) {

// }

// void led_set_user(uint8_t usb_led) {

// }
