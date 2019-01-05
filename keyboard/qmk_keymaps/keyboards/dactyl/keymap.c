#include QMK_KEYBOARD_H
#include "version.h"

#include "../shared/base.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_dactyl(
    // Left hand
    KC_TRANSPARENT, APP_MUSIC, APP_TERMINAL, APP_BROWSER, APP_EDITOR, APP_CHAT,
    KC_DELETE, KC_Q, KC_W, LAYER_NUMPAD_F, LAYER_MOUSE_P, KC_B,
    KC_TAB, HM_A, HM_R, HM_S, HM_T, KC_G,
    OS_COPY_CUT, KC_Z, KC_X, KC_C, KC_D, KC_V,
    OS_PASTE, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT, KC_RIGHT,

    KC_GESC, KC_MEDIA_PLAY_PAUSE,
    KC_TRANSPARENT,
    KC_BSPACE, KC_ENTER, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, EDITOR_DEBUGGER, EDITOR_FILE_TREE_NAVIGATION, EDITOR_TOGGLE_FOLDING, KC_TRANSPARENT,
    KC_J, KC_L, LAYER_SYMBOL_U, KC_Y, KC_SCOLON, KC_TRANSPARENT,
    KC_M, HM_N, HM_E, HM_I, HM_O, KC_QUOTE,
    KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLASH, KC_MINUS,
    KC_UP, KC_DOWN, GENERAL_TAB_NAV, GENERAL_TAB_RECENT, KC_TRANSPARENT,

    LAYER_HUB, KC_CAPSLOCK,
    KC_TRANSPARENT,
    KC_TRANSPARENT, LEADER, KC_SPACE
  ),

  [NUMPAD] = LAYOUT_dactyl(
    // Left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_BSPACE, KC_ENTER, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PERC, KC_KP_SLASH, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_7, KC_8, KC_9, KC_KP_ASTERISK, KC_TRANSPARENT,
    KC_MS_WH_UP, KC_4, KC_5, KC_6, KC_KP_MINUS, KC_TRANSPARENT,
    KC_MS_WH_DOWN, KC_1, KC_2, KC_3, KC_KP_PLUS, KC_TRANSPARENT,
    KC_0, KC_COMMA, KC_DOT, KC_EQUAL, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, LEADER, KC_SPACE
  ),

  [SYMBOLS] = LAYOUT_dactyl(
    // Left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC, KC_AT, SYMBOL_CBR, KC_DLR, KC_PIPE,
    KC_TRANSPARENT, KC_HASH, KC_TILD, SYMBOL_PRN, KC_EQUAL, KC_PLUS,
    KC_TRANSPARENT, KC_CIRC, KC_EXLM, SYMBOL_BRACKET, KC_AMPR, KC_ASTR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLASH, KC_GRAVE,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_BSPACE, KC_ENTER, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LSHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, LEADER, KC_SPACE
  ),

  [MOUSE] = LAYOUT_dactyl(
    // Left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_MS_ACCEL0, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_MS_BTN1, KC_MS_BTN2, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_PGUP, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_PGDOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, LEADER, KC_MS_BTN3
  ),

  [HUB_LAYER] = LAYOUT_dactyl(
    // Left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, TO(QWERTY), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, TO(RESET_LAYER), KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    TO(BASE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [QWERTY] = LAYOUT_dactyl(
    // Left hand
    KC_GRAVE, KC_1, KC_2, KC_3, KC_3, KC_5,
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,
    KC_CAPSLOCK, KC_A, KC_S, KC_D, KC_F, KC_G,
    KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT, KC_RIGHT,

    KC_ESCAPE, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_ENTER, KC_BSPACE, KC_TRANSPARENT,

    // Right hand
    KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS,
    KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLASH,
    KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE,
    KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_TRANSPARENT,
    KC_UP, KC_DOWN, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    TO(BASE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ),

  [RESET_LAYER] = LAYOUT_dactyl(
    // Left hand
    KC_A, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, VRSN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    RESET, KC_TRANSPARENT, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT,
    TO(BASE),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};
