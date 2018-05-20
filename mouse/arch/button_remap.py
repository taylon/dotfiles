#!/usr/bin/python
# https://github.com/PyUserInput/PyUserInput

from pymouse import PyMouseEvent
from pykeyboard import PyKeyboard

k = PyKeyboard()


class MouseToButton(PyMouseEvent):
    def click(self, x, y, button, press):
        # 8 is the back button
        if button == 8:
            if press:
                k.press_key(k.windows_l_key)
            else:  # release
                k.release_key(k.windows_l_key)

    def scroll(self, vertical=None, horizontal=None, depth=None, direction=None):
        # Scroll clicked to the right
        if direction == -1:
            win = k.windows_l_key
            backslash = '\\'

            k.press_key(win)
            k.press_key(backslash)

            k.release_key(backslash)
            k.release_key(win)


C = MouseToButton()
C.run()
