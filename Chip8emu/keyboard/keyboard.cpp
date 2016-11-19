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
	for (u8 i = 0; i < KEY_MATRIX_SIZE; i++)
	{
		pressedKeyMatrix[i] = false;
	}
	numberOfPressedKeys = 0;
}

Keyboard::~Keyboard()
{
}

void Keyboard::UpdateKeyState(u8 keyCode, bool pressed)
{
	u8 safeKeyCode = (keyCode % KEY_MATRIX_SIZE);
	pressedKeyMatrix[safeKeyCode] = pressed;
	if (pressed)
		numberOfPressedKeys++;
	else
		numberOfPressedKeys--;
}

bool Keyboard::isKeyPressed(u8 keyCode)
{
	u8 safeKeyCode = (keyCode % KEY_MATRIX_SIZE);
	return pressedKeyMatrix[safeKeyCode];
}

bool Keyboard::isAnyKeyPressed()
{
	return (numberOfPressedKeys > 0);
}

u8 Keyboard::GetLastPressedKey()
{
	if (numberOfPressedKeys > 0)
	{
		return lastPressedKey;
	}
	return NO_KEY_PRESSED;
}



