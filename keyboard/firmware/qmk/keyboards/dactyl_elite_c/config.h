// #define USER_PRINT
//
//#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x3060
#define DEVICE_VER      0x0001
#define DESCRIPTION     A split keyboard
#define PRODUCT         Dactyl

#define MASTER_LEFT

#define SOFT_SERIAL_PIN D0

#define MATRIX_ROWS 12
#define MATRIX_COLS 6

#define DIODE_DIRECTION COL2ROW
// #define DIODE_DIRECTION ROW2COL

// #define MATRIX_COL_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4 }
// #define MATRIX_ROW_PINS { F5, F6, F7, B1, B3, B2 }
#define MATRIX_ROW_PINS { B2, B3, B1, F7, F6, F5 }

#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

