#include QMK_KEYBOARD_H
#include "./shared/base.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_60_hhkb(
		KC_GESC,       KC_1,    KC_2, KC_3,           KC_4, KC_5, KC_6, KC_7, KC_8,           KC_9,   KC_0,      KC_MINS,       KC_EQL,  KC_BSLS, KC_BSPACE,
		KC_DEL,        KC_Q,    KC_W, LAYER_NUMPAD_F, KC_P, KC_B, KC_J, KC_L, LAYER_SYMBOL_U, KC_Y,   KC_SCOLON, KC_LBRC,       KC_RBRC, KC_BSPC,
		KC_TAB,        HM_A,    HM_R, HM_S,           KC_T, KC_G, KC_M, KC_N, HM_E,           HM_I,   HM_O,      KC_QUOTE,      KC_ENT,
		OSM(MOD_LSFT), KC_Z,    KC_X, KC_C,           KC_D, KC_V, KC_K, KC_H, KC_COMMA,       KC_DOT, KC_SLASH,  OSM(MOD_LSFT), KC_TRNS,
		       KC_TRNS, LEADER,                        LT(ARROWS, KC_SPC),                 GENERAL_TAB_RECENT,      EDITOR_BACK_ON_JUMP_LIST
  ),

  [NUMPAD] = LAYOUT_60_hhkb(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_ASTERISK, KC_PERC,  KC_KP_SLASH, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_KP_MINUS,    KC_TRNS,  KC_TRNS,     KC_TRNS,          
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,    KC_KP_PLUS,     KC_TRNS,  KC_TRNS,                      
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS,        KC_TRNS,  KC_TRNS, 
	           KC_TRNS, KC_TRNS,                            KC_0,                                           KC_TRNS,  KC_TRNS 
  ),

  [ARROWS] = LAYOUT_60_hhkb(
		KC_TRNS, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3), HYPR(KC_4), HYPR(KC_5), KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LEFT, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                  
		KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_UP,   KC_DOWN,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		         KC_TRNS,    KC_TRNS,                            KC_TRNS,                                                  KC_TRNS, KC_TRNS
  ),

  [SYMBOLS] = LAYOUT_60_hhkb(
		KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,        KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		KC_TRNS, KC_PERC,   KC_AT,   SYMBOL_CBR,     KC_DLR,   KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          
		KC_TRNS, KC_HASH,   KC_TILD, SYMBOL_PRN,     KC_EQUAL, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   
		KC_TRNS, KC_CIRC,   KC_EXLM, SYMBOL_BRACKET, KC_AMPR,  KC_ASTR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		         KC_BSLASH, KC_GRAVE,                         KC_TRNS,                                      KC_TRNS,  KC_TRNS
  ),

  [GAMING] = LAYOUT_60_hhkb(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_TRNS,
             KC_LCTL, KC_LALT,                            KC_SPC,                             KC_LGUI, KC_LCTL
  ),

};
