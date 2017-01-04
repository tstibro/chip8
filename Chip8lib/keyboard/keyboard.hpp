/*
 * keyboard.hpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Tomas Stibrany
 */

#ifndef IO_INPUT_KEYBOARD_HPP_
#define IO_INPUT_KEYBOARD_HPP_
#include "../chip8Types.hpp"

#define KEY_MATRIX_SIZE 16
#define NO_KEY_PRESSED 0xff

namespace chip8 { namespace io { namespace input
{

	class Keyboard
	{
	private:
		bool pressedKeyMatrix[KEY_MATRIX_SIZE];
		u8 numberOfPressedKeys;
		u8 lastPressedKey;
	public:
		Keyboard();
		virtual ~Keyboard();

		void UpdateKeyState(u8 keyCode, bool pressed);

		bool isKeyPressed(u8 keyCode);
		bool isAnyKeyPressed();
		u8 GetLastPressedKey();
	};

}}}




#endif /* IO_INPUT_KEYBOARD_HPP_ */
