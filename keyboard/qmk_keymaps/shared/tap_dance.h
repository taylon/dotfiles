// Tap Dance Declarations
enum {
  // Layers
  TD_LAYER_HUB = 0,

  // Symbols
  TD_PRN,
  TD_CBR,
  TD_BRACKET,

  // Shortcuts
  TD_FOLD,
  TD_COPY_CUT,
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  // Layers
  [TD_LAYER_HUB] = ACTION_TAP_DANCE_DUAL_ROLE(KC_ESCAPE, HUB_LAYER),

  // Symbols
  [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
  [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
  [TD_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LBRACKET, KC_RBRACKET),

#ifdef IS_MACOS

  [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LGUI(KC_C), LGUI(KC_X)),

#else

  [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_C), LCTL(KC_X)),

#endif

};
