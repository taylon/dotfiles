#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x0000
#define DEVICE_VER      0x0001
#define MANUFACTURER    Taylon Silmer
#define PRODUCT         gaming_dactyl
#define DESCRIPTION     Custom Dactyl specifically for gaming

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
*/
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, F7 }
#define MATRIX_COL_PINS { B1, B2, B3, B7, D0, D1 }
// #define MATRIX_COL_PINS { D1, D0, B7, B3, B2, B1 }
// #define UNUSED_PINS

/* COL2ROW, ROW2COL*/
// #define DIODE_DIRECTION ROW2COL
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT

// #define USER_PRINT
