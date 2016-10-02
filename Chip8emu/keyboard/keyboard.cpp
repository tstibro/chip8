/*
 * keyboard.cpp
 *
 *  Created on: Jul 25, 2016
 *      Author: Tomas Stibrany
 */
#include "keyboard.hpp"

using namespace chip8::io::input;

Keyboard::Keyboard()
{
}

Keyboard::~Keyboard()
{
}

void Keyboard::KeyPressed(u8 keyCode)
{
	u8 safeKeyCode = (keyCode % KEY_MATRIX_SIZE);
	pressedKeyMatrix[safeKeyCode] = true;
}

void Keyboard::KeyReleased(u8 keyCode)
{
	u8 safeKeyCode = (keyCode % KEY_MATRIX_SIZE);
	pressedKeyMatrix[safeKeyCode] = false;
}

u8 Keyboard::GetPressedKey()
{
	for(u8 i = 0; i < KEY_MATRIX_SIZE; i++)
	{
		if (pressedKeyMatrix[i])
			return i;
	}
	return NO_KEY_PRESSED_RETURN_VALUE;
}



