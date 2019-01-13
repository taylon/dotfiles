// Application switching
#define APP_MUSIC HYPR(KC_1)
#define APP_TERMINAL HYPR(KC_2)
#define APP_BROWSER HYPR(KC_3)
#define APP_EDITOR HYPR(KC_4)
#define APP_CHAT HYPR(KC_5)

// Layer Swithing
#define LAYER_NUMPAD_F LT(NUMPAD, KC_F)
#define LAYER_MOUSE_P LT(MOUSE, KC_P)
#define LAYER_SYMBOL_U LT(SYMBOLS, KC_U)
#define LAYER_HUB TD(TD_LAYER_HUB)

// Editor functionality
#define EDITOR_FILE_TREE_NAVIGATION LCTL(KC_BSLASH)
#define EDITOR_TOGGLE_FOLDING TD(TD_FOLD)
#define EDITOR_DEBUGGER LGUI(KC_5)

// OS functionality
#define OS_COPY_CUT TD(TD_COPY_CUT)
#ifdef IS_MACOS
#define OS_PASTE LGUI(KC_V)
#else
#define OS_PASTE LCTL(KC_V)
#endif

// General functionalities
#define LEADER HYPR(KC_L)
#define GENERAL_TAB_NAV LCTL(LSFT(KC_TAB))
#define GENERAL_TAB_RECENT LCTL(KC_TAB)

// Symbols
#define SYMBOL_CBR TD(TD_CBR)
#define SYMBOL_PRN TD(TD_PRN)
#define SYMBOL_BRACKET TD(TD_BRACKET)

// Home Row Mods
#ifdef IS_MACOS

#define HM_A LCTL_T(KC_A)
#define HM_S GUI_T(KC_S)

#define HM_E GUI_T(KC_E)
#define HM_O LCTL_T(KC_O)

#else

#define HM_A GUI_T(KC_A)
#define HM_S LCTL_T(KC_S)

#define HM_E LCTL_T(KC_E)
#define HM_O GUI_T(KC_O)

#endif

#define HM_R ALT_T(KC_R)
#define HM_T SFT_T(KC_T)

#define HM_N SFT_T(KC_N)
#define HM_I ALT_T(KC_I)
