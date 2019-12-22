// -*- mode: c++ -*-
#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for LED modes that set all LEDs to a single color
#include "Kaleidoscope-LEDEffect-SolidColor.h"

// Support for shared palettes for other plugins, like Colormap below
#include "Kaleidoscope-LED-Palette-Theme.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// Support for Keyboardio's internal keyboard testing mode
#include "Kaleidoscope-HardwareTestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// My Plugins
#include <Kaleidoscope-Qukeys.h>
#include <Kaleidoscope-OneShot.h>
#include <Kaleidoscope-Escape-OneShot.h>
#include <Kaleidoscope-TapDance.h>

/** This 'enum' is a list of all the macros used by the Model 01's firmware
  * The names aren't particularly important. What is important is that each
  * is unique.
  *
  * These are the names of your macros. They'll be used in two places.
  * The first is in your keymap definitions. There, you'll use the syntax
  * `M(MACRO_NAME)` to mark a specific keymap position as triggering `MACRO_NAME`
  *
  * The second usage is in the 'switch' statement in the `macroAction` function.
  * That switch statement actually runs the code associated with a macro when
  * a macro key is pressed.
  */

/* enum {  */
/*   MACRO_VERSION_INFO, */
/*   MACRO_ANY */
/* }; */



/** The Model 01's key layouts are defined as 'keymaps'. By default, there are three
  * keymaps: The standard QWERTY keymap, the "Function layer" keymap and the "Numpad"
  * keymap.
  *
  * Each keymap is defined as a list using the 'KEYMAP_STACKED' macro, built
  * of first the left hand's layout, followed by the right hand's layout.
  *
  * Keymaps typically consist mostly of `Key_` definitions. There are many, many keys
  * defined as part of the USB HID Keyboard specification. You can find the names
  * (if not yet the explanations) for all the standard `Key_` defintions offered by
  * Kaleidoscope in these files:
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keyboard.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_consumerctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_sysctl.h
  *    https://github.com/keyboardio/Kaleidoscope/blob/master/src/key_defs_keymaps.h
  *
  * Additional things that should be documented here include
  *   using ___ to let keypresses fall through to the previously active layer
  *   using XXX to mark a keyswitch as 'blocked' on this layer
  *   using ShiftToLayer() and LockLayer() keys to change the active keymap.
  *   keeping NUM and FN consistent and accessible on all layers
  *
  * The PROG key is special, since it is how you indicate to the board that you
  * want to flash the firmware. However, it can be remapped to a regular key.
  * When the keyboard boots, it first looks to see whether the PROG key is held
  * down; if it is, it simply awaits further flashing instructions. If it is
  * not, it continues loading the rest of the firmware and the keyboard
  * functions normally, with whatever binding you have set to PROG. More detail
  * here: https://community.keyboard.io/t/how-the-prog-key-gets-you-into-the-bootloader/506/8
  *
  * The "keymaps" data structure is a list of the keymaps compiled into the firmware.
  * The order of keymaps in the list is important, as the ShiftToLayer(#) and LockLayer(#)
  * macros switch to key layers based on this list.
  *
  *

  * A key defined as 'ShiftToLayer(FUNCTION)' will switch to FUNCTION while held.
  * Similarly, a key defined as 'LockLayer(NUMPAD)' will switch to NUMPAD when tapped.
  */

 // Layers
enum { 
  PRIMARY,
  NUMPAD, 
  SYMBOLS,
  ARROWS, 
};

// Custom keycodes
#define Key_Dollar LSHIFT(Key_4)
#define Key_Hash LSHIFT(Key_3)
#define Key_Tilde LSHIFT(Key_Backtick)
#define Key_Plus LSHIFT(Key_Equals)
#define Key_Circumflex LSHIFT(Key_6)
#define Key_Exclamation LSHIFT(Key_1)
#define Key_Ampersand LSHIFT(Key_7)
#define Key_Asterisk LSHIFT(Key_8)

// TapDance
enum {
  CURLY_BRACKETS,
  SQUARE_BRACKETS,
  PARENTHESIS,
};

void tapDanceAction(uint8_t tap_dance_index, 
                    byte row, 
                    byte col, 
                    uint8_t tap_count,
                    kaleidoscope::plugin::TapDance::ActionType tap_dance_action) {
  switch (tap_dance_index) {
    case CURLY_BRACKETS:
      return tapDanceActionKeys(tap_count, tap_dance_action,
                                Key_LeftCurlyBracket, Key_RightCurlyBracket);

    case SQUARE_BRACKETS:
      return tapDanceActionKeys(tap_count, tap_dance_action,
                                Key_LeftBracket, Key_RightBracket);

    case PARENTHESIS:
      return tapDanceActionKeys(tap_count, tap_dance_action,
                                Key_LeftParen, Key_RightParen);
  }
}

// *INDENT-OFF*
KEYMAPS(

  [PRIMARY] = KEYMAP_STACKED(
    ___,        Key_F13,  Key_F14,  Key_F15,       Key_F16, Key_F17, Key_LEDEffectNext,
    Key_Delete, Key_Q,    Key_W,    LT(NUMPAD, F), Key_P,   Key_B,   Key_Tab,
    Key_Tab,    GUI_T(A), ALT_T(R), CTL_T(S),      Key_T,   Key_G,
    Key_Copy,   Key_Z,    Key_X,    Key_C,         Key_D,   Key_V,   Key_Escape,

     OSM(LeftShift), LT(ARROWS, Backspace), Key_F1, OSM(LeftShift),
     ShiftToLayer(ARROWS),

    Key_F8,       Key_6, Key_7, Key_8,     Key_9,      Key_F19,       LockLayer(NUMPAD),
    Key_F18,      Key_J, Key_L, Key_U,     Key_Y,      Key_Semicolon, Key_Equals,
                  Key_M, Key_N, CTL_T(E),  ALT_T(I),   GUI_T(O),      Key_Quote,
    Key_RightAlt, Key_K, Key_H, Key_Comma, Key_Period, Key_Slash,     Key_Minus,

     Key_F1, Key_Enter, Key_Spacebar, OSL(SYMBOLS),
     ShiftToLayer(SYMBOLS)
  ),

  [NUMPAD] = KEYMAP_STACKED(
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,

      ___, ___, ___, ___,
      ___,

    ___,  ___, ___,   Key_Period, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
    ___,  ___, Key_7, Key_8,      Key_9,              Key_KeypadSubtract, ___,
          ___, Key_4, Key_5,      Key_6,              Key_KeypadAdd,      ___,
    ___,  ___, Key_1, Key_2,      Key_3,              Key_Equals,         ___,

      ___, ___, ___, Key_0,
      ___
  ),

  [SYMBOLS] = KEYMAP_STACKED(
    ___, ___, ___, ___, ___, ___, ___,
    ___, Key_KeypadPercent, Key_KeypadAtSign, TD(CURLY_BRACKETS),  Key_Dollar,    Key_Pipe,     ___,
    ___, Key_Hash,          Key_Tilde,        TD(PARENTHESIS),     Key_Equals,    Key_Plus,
    ___, Key_Circumflex,    Key_Exclamation,  TD(SQUARE_BRACKETS), Key_Ampersand, Key_Asterisk, ___,

      Key_Backtick, Key_Backslash, ___, ___,
      ___,

    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
         ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,

      ___, ___, ___, ___,
      ___
  ),

  [ARROWS] = KEYMAP_STACKED(
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___,
    ___, ___, ___, ___, ___, ___, ___,

      ___, ___, ___, ___,
      ___,

    ___, Key_LeftArrow, Key_RightArrow, Key_PageUp, Key_PageUp, ___, ___,
    ___, ___,           ___,            ___,        ___,        ___, ___,
         ___,           ___,            ___,        ___,        ___, ___,
    ___, Key_UpArrow,   Key_DownArrow,  ___,        ___,        ___, ___,

      ___, ___, ___, ___,
      ___
  ),

) 
// KEYMAPS
// *INDENT-ON*

/** versionInfoMacro handles the 'firmware version info' macro
 *  When a key bound to the macro is pressed, this macro
 *  prints out the firmware build information as virtual keystrokes
 */

/* static void versionInfoMacro(uint8_t keyState) { */
/*   if (keyToggledOn(keyState)) { */
/*     Macros.type(PSTR("Keyboardio Model 01 - Kaleidoscope ")); */
/*     Macros.type(PSTR(BUILD_INFORMATION)); */
/*   } */
/* } */

/** anyKeyMacro is used to provide the functionality of the 'Any' key.
 *
 * When the 'any key' macro is toggled on, a random alphanumeric key is
 * selected. While the key is held, the function generates a synthetic
 * keypress event repeating that randomly selected key.
 *
 */

/* static void anyKeyMacro(uint8_t keyState) { */
/*   static Key lastKey; */
/*   bool toggledOn = false; */
/*   if (keyToggledOn(keyState)) { */
/*     lastKey.setKeyCode(Key_A.getKeyCode() + (uint8_t)(millis() % 36)); */
/*     toggledOn = true; */
/*   } */
/*  */
/*   if (keyIsPressed(keyState)) */
/*     kaleidoscope::hid::pressKey(lastKey, toggledOn); */
/* } */


/** macroAction dispatches keymap events that are tied to a macro
    to that macro. It takes two uint8_t parameters.

    The first is the macro being called (the entry in the 'enum' earlier in this file).
    The second is the state of the keyswitch. You can use the keyswitch state to figure out
    if the key has just been toggled on, is currently pressed or if it's just been released.

    The 'switch' statement should have a 'case' for each entry of the macro enum.
    Each 'case' statement should call out to a function to handle the macro in question.

 */

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  /* switch (macroIndex) { */
  /*  */
  /* case MACRO_VERSION_INFO: */
  /*   versionInfoMacro(keyState); */
  /*   break; */

  /* case MACRO_ANY: */
  /*   anyKeyMacro(keyState); */
  /*   break; */
  /* } */

  return MACRO_NONE;
}



// These 'solid' color effect definitions define a rainbow of
// LED color modes calibrated to draw 500mA or less on the
// Keyboardio Model 01.


static kaleidoscope::plugin::LEDSolidColor solidRed(160, 0, 0);
static kaleidoscope::plugin::LEDSolidColor solidOrange(140, 70, 0);
static kaleidoscope::plugin::LEDSolidColor solidYellow(130, 100, 0);
static kaleidoscope::plugin::LEDSolidColor solidGreen(0, 160, 0);
static kaleidoscope::plugin::LEDSolidColor solidBlue(0, 70, 130);
static kaleidoscope::plugin::LEDSolidColor solidIndigo(0, 0, 170);
static kaleidoscope::plugin::LEDSolidColor solidViolet(130, 0, 120);

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    LEDControl.paused = true;
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE,
  // Enter test mode
  COMBO_ENTER_TEST_MODE
};

/** Wrappers, to be used by MagicCombo. **/

/**
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/**
 *  This enters the hardware test mode
 */
static void enterHardwareTestMode(uint8_t combo_index) {
  HardwareTestMode.runTests();
}


/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
}, {
  .action = enterHardwareTestMode,
  // Left Fn + Prog + LED
  .keys = { R3C6, R0C0, R0C6 }
});

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  BootGreetingEffect,

  // LEDControl provides support for other LED modes
  LEDControl,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // These static effects turn your keyboard's LEDs a variety of colors
  solidRed, solidOrange, solidYellow, solidGreen, solidBlue, solidIndigo, solidViolet,

  // The LED Palette Theme plugin provides a shared palette for other plugins,
  // like Colormap below
  LEDPaletteTheme,

  // The Colormap effect makes it possible to set up per-layer colormaps
  ColormapEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,

  // My Plugins
  Qukeys,
  OneShot,
  EscapeOneShot,
  TapDance
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  // First, call Kaleidoscope's internal setup function
  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // Set the action key the test mode should listen for to Left Fn
  HardwareTestMode.setActionKey(R3C6);

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  LEDOff.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(5);

  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(5);
}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
