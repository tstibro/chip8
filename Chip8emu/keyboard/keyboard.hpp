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
#define NO_KEY_PRESSED_RETURN_VALUE -1

namespace chip8 { namespace io { namespace input
{

	class Keyboard
	{
	private:
		bool pressedKeyMatrix[KEY_MATRIX_SIZE];
	public:
		Keyboard();
		virtual ~Keyboard();

		void KeyPressed(u8 keyCode);
		void KeyReleased(u8 keyCode);

		u8 GetPressedKey();
	};

}}}




#endif /* IO_INPUT_KEYBOARD_HPP_ */
