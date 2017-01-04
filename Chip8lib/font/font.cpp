/*
 * defaultFont.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */
#include "font.hpp"

using namespace chip8::font;

Font::Font()
{
	this->characters = new FontChar[16];
	this->characterCount = 16;
	initialize();
}

void Font::initialize()
{
	this->characters[0x00].ReSetFont('0', 5, 0xF0, 0x90, 0x90, 0x90, 0xF0);
	this->characters[0x01].ReSetFont('1', 5, 0x20, 0x60, 0x20, 0x20, 0x70);
	this->characters[0x02].ReSetFont('2', 5, 0xF0, 0x10, 0xF0, 0x80, 0xF0);
	this->characters[0x03].ReSetFont('3', 5, 0xF0, 0x10, 0xF0, 0x10, 0xF0);
	this->characters[0x04].ReSetFont('4', 5, 0x90, 0x90, 0xF0, 0x10, 0x10);
	this->characters[0x05].ReSetFont('5', 5, 0xF0, 0x80, 0xF0, 0x10, 0xF0);
	this->characters[0x06].ReSetFont('6', 5, 0xF0, 0x80, 0xF0, 0x90, 0xF0);
	this->characters[0x07].ReSetFont('7', 5, 0xF0, 0x10, 0x20, 0x40, 0x40);
	this->characters[0x08].ReSetFont('8', 5, 0xF0, 0x90, 0xF0, 0x90, 0xF0);
	this->characters[0x09].ReSetFont('9', 5, 0xF0, 0x90, 0xF0, 0x10, 0xF0);
	this->characters[0x0A].ReSetFont('A', 5, 0xF0, 0x90, 0xF0, 0x90, 0x90);
	this->characters[0x0B].ReSetFont('B', 5, 0xE0, 0x90, 0xE0, 0x90, 0xE0);
	this->characters[0x0C].ReSetFont('C', 5, 0xF0, 0x80, 0x80, 0x80, 0xF0);
	this->characters[0x0D].ReSetFont('D', 5, 0xE0, 0x90, 0x90, 0x90, 0xE0);
	this->characters[0x0E].ReSetFont('E', 5, 0xF0, 0x80, 0xF0, 0x80, 0xF0);
	this->characters[0x0F].ReSetFont('F', 5, 0xF0, 0x80, 0xF0, 0x80, 0x80);
}

Font::~Font()
{
	delete this->characters;
	this->characterCount = 0;
}

u8 Font::GetCharacterCount()
{
	return this->characterCount;
}

FontChar *Font::GetCharacterByCode(char charCode)
{
	for(u8 i = 0; i < this->characterCount; i++)
	{
		if (this->characters[i].GetCharCode() == charCode)
		{
			return &this->characters[i];
		}
	}
	return 0;
}

FontChar *Font::GetCharacterByIndex(u8 index)
{
	return &this->characters[index];
}


