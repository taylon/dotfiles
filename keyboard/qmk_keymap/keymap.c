#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include "keymap_german.h"

#include "keymap_nordic.h"


enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD,
};

// Layers
enum {
  BASE = 0,
  NUMPAD,
  SYMBOLS,
  MOUSE,
  LEDS,
  QWERTY
};

// Tap Dance Declarations
enum {
  // Symbols
  TD_PRN = 0,
  TD_CBR,
  TD_BRACKET
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Symbols
  [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = KEYMAP(
    // Left hand
    KC_ESCAPE      , KC_1           , KC_2           , KC_3             , KC_4            , KC_5 , TG(QWERTY)     ,
    KC_DELETE      , KC_Q           , KC_W           , LT(NUMPAD, KC_F) , LT(MOUSE, KC_P) , KC_B , KC_TRANSPARENT ,
    KC_BSPACE      , LCTL_T(KC_A)    , ALT_T(KC_R)   , GUI_T(KC_S)      , SFT_T(KC_T)     , KC_G ,
    KC_TRANSPARENT , KC_Z           , KC_X           , KC_C             , KC_D            , KC_V , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_LEFT          , KC_RIGHT        ,

    KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_ENTER, KC_TAB, KC_TRANSPARENT ,

    // Right hand
    TG(LEDS)       , KC_6        , KC_7                    , KC_8                    , KC_9           , KC_0      , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_J        , KC_L                    , LT(SYMBOLS, KC_U)       , KC_Y           , KC_SCOLON , KC_BSLASH      ,
    KC_M           , SFT_T(KC_N) , GUI_T(KC_E)             , ALT_T(KC_I)             , LCTL_T(KC_O)   , KC_QUOTE  ,
    KC_TRANSPARENT , KC_K        , KC_H                    , KC_COMMA                , KC_DOT         , KC_SLASH  , KC_MINUS       ,
    KC_UP          , KC_DOWN     , LCTL(LSFT(KC_TAB))      , LCTL(KC_TAB)            , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ) ,

  [NUMPAD] = KEYMAP(
    // Left hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_ENTER, KC_TAB, KC_TRANSPARENT ,

    // Right hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_PERC        , KC_KP_SLASH    , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_7           , KC_8           , KC_9           , KC_KP_ASTERISK , KC_TRANSPARENT ,
    KC_MS_WH_UP    , KC_4           , KC_5           , KC_6           , KC_KP_MINUS    , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_MS_WH_DOWN  , KC_1           , KC_2           , KC_3           , KC_KP_PLUS     , KC_TRANSPARENT ,
    KC_0           , KC_COMMA       , KC_DOT         , KC_EQUAL       , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ) ,

  [SYMBOLS] = KEYMAP(
    // Left hand
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_PERC       , KC_AT         , TD(TD_CBR)     , KC_DLR        , KC_PIPE       , KC_TRANSPARENT,
    KC_BSPACE     , KC_HASH       , KC_TILD       , TD(TD_PRN)     , KC_EQUAL      , KC_PLUS       ,
    KC_TRANSPARENT, KC_CIRC       , KC_EXLM       , TD(TD_BRACKET) , KC_AMPR       , KC_ASTR       , KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT , KC_GRAVE      ,

    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,
    KC_ENTER, KC_TAB, KC_TRANSPARENT,

    // Right hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_LSHIFT      , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE
  ) ,

  [MOUSE] = KEYMAP(
    // Left hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_MS_ACCEL1   , KC_MS_ACCEL2   , KC_MS_ACCEL0   , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_MS_BTN1, KC_MS_BTN2, KC_TRANSPARENT ,

    // Right hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_MS_UP       , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_MS_WH_UP    , KC_MS_LEFT     , KC_MS_DOWN     , KC_MS_RIGHT    , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_MS_WH_DOWN  , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT, KC_TRANSPARENT ,
    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3
  ) ,


  [LEDS] = KEYMAP(
    // Left hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    RGB_MOD , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    RGB_VAD , RGB_VAI , KC_TRANSPARENT ,

    // Right hand
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    RGB_TOG , RGB_SLD ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , RGB_HUD , RGB_HUI
  ) ,

  [QWERTY] = KEYMAP(
    // Left hand
    KC_GRAVE       , KC_1           , KC_2           , KC_3    , KC_3     , KC_5 , KC_TRANSPARENT ,
    KC_TAB         , KC_Q           , KC_W           , KC_E    , KC_R     , KC_T , KC_TRANSPARENT ,
    KC_CAPSLOCK    , KC_A           , KC_R           , KC_D    , KC_F     , KC_G ,
    KC_LSHIFT      , KC_Z           , KC_X           , KC_C    , KC_V     , KC_B , KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT , KC_LEFT , KC_RIGHT ,

    KC_ESCAPE , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_ENTER , KC_BSPACE , KC_TRANSPARENT ,

    // Right hand
    KC_TRANSPARENT , KC_6    , KC_7           , KC_8           , KC_9           , KC_0     , KC_MINUS       ,
    KC_TRANSPARENT , KC_Y    , KC_U           , KC_I           , KC_O           , KC_P     , KC_BSLASH      ,
    KC_H           , KC_J    , KC_K           , KC_L           , KC_SCOLON      , KC_QUOTE ,
    KC_TRANSPARENT , KC_N    , KC_M           , KC_COMMA       , KC_DOT         , KC_SLASH , KC_TRANSPARENT ,
    KC_UP          , KC_DOWN , KC_TRANSPARENT , KC_TRANSPARENT , KC_TRANSPARENT ,

    KC_TRANSPARENT , KC_TRANSPARENT ,
    KC_TRANSPARENT ,
    KC_TRANSPARENT , KC_TRANSPARENT , KC_SPACE
  ),
};

// From here it is all default stuff from the Ergodox EZ

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
      break;

  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }
    return state;

};
