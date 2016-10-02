/*
 * fontLoader.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */
#include "fontLoader.hpp"
#include "font.hpp"
#include "fontChar.hpp"
#include "../core/memory/ram.hpp"

using namespace chip8::font;

FontLoader::FontLoader()
{
}

FontLoader::~FontLoader()
{
}

void FontLoader::LoadTo(RAM *ram, Font *font)
{
	u16 address = ram->GetFontDataStartAddress();
	// TODO: When more fonts will be added, check the size of font space
	for(u8 charIndex = 0; charIndex < font->GetCharacterCount(); charIndex++)
	{
		FontChar *curChar = font->GetCharacterByIndex(charIndex);
		// TODO: Make rowCount constant in Font.
		for(u8 rowIndex = 0; rowIndex < curChar->GetRowCount(); rowIndex++)
		{
			ram->Write(address + (charIndex * curChar->GetRowCount()) + rowIndex, curChar->GetRow(rowIndex));
		}
	}
}



