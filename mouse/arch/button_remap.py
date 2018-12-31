#!/usr/bin/python
# https://github.com/PyUserInput/PyUserInput

from pymouse import PyMouseEvent
from pykeyboard import PyKeyboard

kbd = PyKeyboard()


class MouseHandler(PyMouseEvent):
    def click(self, x, y, button, press):
        # 8 is the back button
        if button == 8:
            if press:
                kbd.press_key(kbd.windows_l_key)
            else:  # release
                kbd.release_key(kbd.windows_l_key)

    def scroll(self, vertical=None, horizontal=None, depth=None, direction=None):
        # Scroll clicked to the right
        if direction == -1:
            win = kbd.windows_l_key
            backslash = '\\'

            kbd.press_key(win)
            kbd.press_key(backslash)

            kbd.release_key(backslash)
            kbd.release_key(win)


mouse_handler = MouseHandler()
mouse_handler.run()
