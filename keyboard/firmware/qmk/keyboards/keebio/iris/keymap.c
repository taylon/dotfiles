#include QMK_KEYBOARD_H

#include "./shared/custom_keys.h"

// Layers
enum {
  BASE = 0,
  NUMPAD,
  SYMBOLS,
  HUB_LAYER,
  RESET_LAYER,
  ARROWS,
};

// App switching
#define CK_Music KC_F1
#define CK_Browser KC_F2
#define CK_Vim KC_F3
#define CK_Terminal KC_F4
#define CK_Chat KC_F5

// Symbols
#define CK_CBR TD(TD_CBR)
#define CK_PRN TD(TD_PRN)
#define CK_Bracket TD(TD_BRACKET)

// General
#define CK_Forward KC_F7
#define CK_Back KC_F10
#define CK_FileNavigation KC_F12
#define CK_Leader KC_F6

// Layer Swithing
#define CK_Numpad_F LT(NUMPAD, KC_F)
#define LAYER_SYMBOL_U LT(SYMBOLS, KC_U)
#define LAYER_HUB TD(TD_LAYER_HUB)

// Tap Dance
enum {
  // Layers
  TD_LAYER_HUB = 0,

  // Symbols
  TD_PRN,
  TD_CBR,
  TD_BRACKET,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // Layers
  [TD_LAYER_HUB] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESCAPE, HUB_LAYER),

  // Symbols
  [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT(
    KC_GESC, CK_Music, CK_Terminal, CK_Browser, CK_Vim, CK_Chat,         KC_TRNS, KC_TRNS, CK_Leader, CK_Back, CK_Forward, KC_TRNS,
    KC_DELETE, KC_Q, KC_W, LAYER_NUMPAD_F, KC_P, KC_B,                   KC_J, KC_L, LAYER_SYMBOL_U, KC_Y, KC_SCOLON, KC_TRNS,
    KC_TAB, HM_A, HM_R, HM_S, HM_T, KC_G,                                KC_M, HM_N, HM_E, HM_I, HM_O, KC_QUOTE,
    KC_COPY, KC_Z, KC_X, KC_C, KC_D, KC_V,   KC_GESC,              CK_FileNavigation, KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLASH, KC_MINUS,

         OSM(MOD_LSFT), KC_BSPC, LT(ARROWS, KC_BSPC),                 KC_ENTER, KC_SPACE, KC_TRNS
  ),

  [NUMPAD] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_PERC, KC_KP_SLASH, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_7, KC_8, KC_9, KC_KP_ASTERISK, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_KP_PLUS, KC_TRNS,

                                        KC_TRNS, KC_TRNS, KC_TRNS,    KC_ENTER, KC_0, KC_TRNS
  ),

  [SYMBOLS] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_PERC, KC_AT, CK_CBR, KC_DLR, KC_PIPE,                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_HASH, KC_TILD, CK_PRN, KC_EQUAL, KC_PLUS,                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_CIRC, KC_EXLM, CK_Bracket, KC_AMPR, KC_ASTR, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                        KC_BSLASH, KC_GRAVE, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [ARROWS] = LAYOUT(
    RGB_VAD, RGB_VAI, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI,                      KC_LEFT, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    RGB_TOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_UP,   KC_DOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

                                        KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS
  )

  /* [] = LAYOUT( */
  /*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
  /*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
  /*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
  /*   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, */
  /*  */
  /*                                       KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS */
  /* ) */

};
