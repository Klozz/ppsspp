#include "base/NativeApp.h"
#include "input/input_state.h"
#include "input/keycodes.h"
#include "util/const_map.h"
#include "KeyMap.h"
#include "ControlMapping.h"
#include "Windows/WndMainWindow.h"
#include "KeyboardDevice.h"
#include "../Common/CommonTypes.h"
#include "../Core/HLE/sceCtrl.h"
#include "WinUser.h"


// TODO: More keys need to be added, but this is more than
// a fair start.
std::map<int, int> windowsTransTable = InitConstMap<int, int>
	('A', KEYCODE_A)
	('B', KEYCODE_B)
	('C', KEYCODE_C)
	('D', KEYCODE_D)
	('E', KEYCODE_E)
	('F', KEYCODE_F)
	('G', KEYCODE_G)
	('H', KEYCODE_H)
	('I', KEYCODE_I)
	('J', KEYCODE_J)
	('K', KEYCODE_K)
	('L', KEYCODE_L)
	('M', KEYCODE_M)
	('N', KEYCODE_N)
	('O', KEYCODE_O)
	('P', KEYCODE_P)
	('Q', KEYCODE_Q)
	('R', KEYCODE_R)
	('S', KEYCODE_S)
	('T', KEYCODE_T)
	('U', KEYCODE_U)
	('V', KEYCODE_V)
	('W', KEYCODE_W)
	('X', KEYCODE_X)
	('Y', KEYCODE_Y)
	('Z', KEYCODE_Z)
	('0', KEYCODE_0)
	('1', KEYCODE_1)
	('2', KEYCODE_2)
	('3', KEYCODE_3)
	('4', KEYCODE_4)
	('5', KEYCODE_5)
	('6', KEYCODE_6)
	('7', KEYCODE_7)
	('8', KEYCODE_8)
	('9', KEYCODE_9)
	(VK_OEM_PERIOD, KEYCODE_PERIOD)
	(VK_OEM_COMMA, KEYCODE_COMMA)
	(VK_NUMPAD0, KEYCODE_NUMPAD_0)
	(VK_NUMPAD1, KEYCODE_NUMPAD_1)
	(VK_NUMPAD2, KEYCODE_NUMPAD_2)
	(VK_NUMPAD3, KEYCODE_NUMPAD_3)
	(VK_NUMPAD4, KEYCODE_NUMPAD_4)
	(VK_NUMPAD5, KEYCODE_NUMPAD_5)
	(VK_NUMPAD6, KEYCODE_NUMPAD_6)
	(VK_NUMPAD7, KEYCODE_NUMPAD_7)
	(VK_NUMPAD8, KEYCODE_NUMPAD_8)
	(VK_NUMPAD9, KEYCODE_NUMPAD_9)
	(VK_DECIMAL, KEYCODE_NUMPAD_DOT)
	(VK_DIVIDE, KEYCODE_NUMPAD_DIVIDE)
	(VK_MULTIPLY, KEYCODE_NUMPAD_MULTIPLY)
	(VK_SUBTRACT, KEYCODE_NUMPAD_SUBTRACT)
	(VK_ADD, KEYCODE_NUMPAD_ADD)
	(VK_SEPARATOR, KEYCODE_NUMPAD_COMMA)
	(VK_OEM_MINUS, KEYCODE_MINUS)
	(VK_OEM_PLUS, KEYCODE_PLUS)
	(VK_LCONTROL, KEYCODE_CTRL_LEFT)
	(VK_RCONTROL, KEYCODE_CTRL_RIGHT)
	(VK_LSHIFT, KEYCODE_SHIFT_LEFT)
	(VK_RSHIFT, KEYCODE_SHIFT_RIGHT)
	(VK_LMENU, KEYCODE_ALT_LEFT)
	(VK_RMENU, KEYCODE_ALT_RIGHT)
	(VK_BACK, KEYCODE_BACK)
	(VK_SPACE, KEYCODE_SPACE)
	(VK_ESCAPE, KEYCODE_ESCAPE)
	(VK_UP, KEYCODE_DPAD_UP)
	(VK_INSERT, KEYCODE_INSERT)
	(VK_HOME, KEYCODE_HOME)
	(VK_PRIOR, KEYCODE_PAGE_UP)
	(VK_NEXT, KEYCODE_PAGE_DOWN)
	(VK_DELETE, KEYCODE_DEL)
	(VK_END, KEYCODE_MOVE_END)
	(VK_TAB, KEYCODE_TAB)
	(VK_DOWN, KEYCODE_DPAD_DOWN)
	(VK_LEFT, KEYCODE_DPAD_LEFT)
	(VK_RIGHT, KEYCODE_DPAD_RIGHT)
	(VK_CAPITAL, KEYCODE_CAPS_LOCK)
	(VK_CLEAR, KEYCODE_CLEAR)
	(VK_SNAPSHOT, KEYCODE_SYSRQ)
	(VK_SCROLL, KEYCODE_SCROLL_LOCK)
	(VK_OEM_1, KEYCODE_SEMICOLON)
	(VK_OEM_2, KEYCODE_SLASH)
	(VK_OEM_3, KEYCODE_GRAVE)
	(VK_OEM_4, KEYCODE_LEFT_BRACKET)
	(VK_OEM_5, KEYCODE_BACKSLASH)
	(VK_OEM_6, KEYCODE_RIGHT_BRACKET)
	(VK_OEM_7, KEYCODE_APOSTROPHE)
	(VK_RETURN, KEYCODE_ENTER)
	(VK_APPS, KEYCODE_MENU) // Context menu key, let's call this "menu".
	(VK_PAUSE, KEYCODE_BREAK)
	(VK_F1, KEYCODE_F1)
	(VK_F2, KEYCODE_F2)
	(VK_F3, KEYCODE_F3)
	(VK_F4, KEYCODE_F4)
	(VK_F5, KEYCODE_F5)
	(VK_F6, KEYCODE_F6)
	(VK_F7, KEYCODE_F7)
	(VK_F8, KEYCODE_F8)
	(VK_F9, KEYCODE_F9)
	(VK_F10, KEYCODE_F10)
	(VK_F11, KEYCODE_F11)
	(VK_F12, KEYCODE_F12)
	(VK_OEM_102, KEYCODE_EXT_PIPE);

int KeyboardDevice::UpdateState(InputState &input_state) {
	// Nothing to do, all done in WM_INPUT
	return 0;
}
