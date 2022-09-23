global window_sizes := {left: 1342, right: 1342, middle: 2436}
global window_positions := {left: 0, right: 3778, middle: 1342}

set_screen_resolution(width, height) {
	VarSetCapacity(device_mode, 156, 0)
	; NumPut(156, device_mode, 36)
	DllCall("EnumDisplaySettingsA", UInt, 0, UInt, -1, UInt, &device_mode)
	; NumPut(0x5c0000, device_mode, 40)
	; NumPut(100, device_mode, 120) ; refresh rate
	;NumPut(32, device_mode, 104) ; color depth
	NumPut(width, device_mode, 108)
	NumPut(height,device_mode, 112)

	Return DllCall("ChangeDisplaySettingsA", UInt, &device_mode, UInt, 0)
}

toggle_screen_resolution() {
  if (A_ScreenWidth = 2560) {
    window_sizes := {left: 1342, right: 1342, middle: 2436}
    window_positions := {left: 0, right: 3778, middle: 1342}

    set_screen_resolution(5120, 1440)
  } else if (A_ScreenWidth = 5120) {
    window_sizes := {left: A_ScreenWidth, right: A_ScreenWidth, middle: A_ScreenWidth}
    window_positions := {left: 0, right: 0, middle: 0}

    set_screen_resolution(2560, 1440)
  }
}

Menu, Tray, Add
Menu, Tray, Add, Toggle screen resolution, toggle_screen_resolution

move_editors(position) {
  window_size := window_sizes[position]
  window_position := window_positions[position]

  WinMove, ahk_exe nvim-qt.exe, , window_position, 0, window_size, A_ScreenHeight
  WinMove, ahk_exe Code.exe, , window_position, 0, window_size, A_ScreenHeight 
  WinMove, ahk_exe devenv.exe, , window_position, 0, window_size, A_ScreenHeight + 4
}

move_browsers(position) {
  window_size := window_sizes[position]
  window_position := window_positions[position]

  WinMove, ahk_exe chrome.exe, , window_position, 0, window_size + 6, A_ScreenHeight + 5
  WinMove, ahk_exe qutebrowser.exe, , window_position, 0, window_size, A_ScreenHeight
}

move_terminal(position) {
  window_size := window_sizes[position]
  window_position := window_positions[position]

  WinMove, ahk_exe WindowsTerminal.exe, , window_position, 0, window_size, A_ScreenHeight
}

is_running(app) {
  Process, Exist, % app
  return ErrorLevel
}

f1::
  WinActivate, ahk_exe p4v.exe

  window_size := window_sizes["middle"]
  window_position := window_positions["middle"]

  WinMove, ahk_exe p4v.exe, , window_position, 0, window_size, A_ScreenHeight
return

^f2::
f2::
  if !is_running("qutebrowser.exe") or WinActive("ahk_exe qutebrowser.exe") {
    WinActivate, ahk_exe chrome.exe
  } else {
    WinSet, Style, -0xC40000, ahk_exe qutebrowser.exe
    WinActivate, ahk_exe qutebrowser.exe
  }

  if !GetKeyState("Ctrl") {
    move_editors("left")
    move_browsers("middle")
    move_terminal("right")
  }
return

f3::
  if !is_running("nvim-qt.exe") or WinActive("ahk_exe nvim-qt.exe") {
    WinActivate, ahk_exe devenv.exe
  } else {
    WinSet, Style, -0xC40000, ahk_exe nvim-qt.exe
    WinActivate, ahk_exe nvim-qt.exe
  }

  move_browsers("left")
  move_editors("middle")
  move_terminal("right")
return

f4::
  WinActivate, ahk_exe WindowsTerminal.exe

  move_browsers("left")
  move_terminal("middle")
  move_editors("right")
return

f5::
  if !is_running("slack.exe") or WinActive("ahk_exe slack.exe") {
    WinActivate, ahk_exe Discord.exe
    WinMove, ahk_exe Discord.exe, , window_positions.middle, 0, window_sizes.middle, A_ScreenHeight
  } else {
    WinActivate, ahk_exe slack.exe
    WinMove, ahk_exe slack.exe, , window_positions.middle, 0, window_sizes.middle, A_ScreenHeight
  }
return

!left::
  WinMove, A, , window_positions.left, 0, window_sizes.left, A_ScreenHeight 
return

!right::
  WinMove, A, , window_positions.right, 0, window_sizes.right, A_ScreenHeight 
return

^q::Send !{F4}
return
