// TODO: Share this with Kaleidoscope

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
#define CK_I3 LCTL(LALT(KC_LGUI))

// Layer Swithing
#define CK_Numpad_F LT(NUMPAD, KC_F)
#define LAYER_SYMBOL_U LT(SYMBOLS, KC_U)
#define LAYER_HUB TD(TD_LAYER_HUB)

// ============================

// Application switching
#define APP_MUSIC KC_F1
#define APP_BROWSER KC_F2
#define APP_EDITOR KC_F3
#define APP_TERMINAL KC_F4
#define APP_CHAT KC_F5

// Layer Swithing
#define LAYER_NUMPAD_F LT(NUMPAD, KC_F)
#define LAYER_SYMBOL_U LT(SYMBOLS, KC_U)
#define LAYER_HUB TD(TD_LAYER_HUB)

// General
#define GENERAL_NEXT_TAB Key_F7
#define GENERAL_PREV_TAB Key_F10
#define GENERAL_FILE_NAVIGATION Key_F12
#define GENERAL_LEADER Key_F6

// OS functionality
#define OS_COPY_CUT TD(TD_COPY_CUT)
#ifdef IS_MACOS
#define OS_PASTE LGUI(KC_V)
#else
#define OS_PASTE LCTL(KC_V)
#endif

// General functionalities
#define LEADER LCTL(KC_BSLASH)
#define GENERAL_TAB_NAV LCTL(LSFT(KC_TAB))
#define GENERAL_TAB_RECENT LCTL(KC_TAB)

// Symbols
#define SYMBOL_CBR TD(TD_CBR)
#define SYMBOL_PRN TD(TD_PRN)
#define SYMBOL_BRACKET TD(TD_BRACKET)

// Home Row Mods
#ifdef IS_MACOS

#define HM_A LCTL_T(KC_A)
#define HM_S LGUI_T(KC_S)

#define HM_E LGUI_T(KC_E)
#define HM_O LCTL_T(KC_O)

#else

#define HM_A LGUI_T(KC_A)
#define HM_S LCTL_T(KC_S)

#define HM_E LCTL_T(KC_E)
#define HM_O LGUI_T(KC_O)

#endif

#define HM_R ALT_T(KC_R)
#define HM_T SFT_T(KC_T)

#define HM_N SFT_T(KC_N)
#define HM_I ALT_T(KC_I)
