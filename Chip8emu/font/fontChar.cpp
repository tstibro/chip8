/*
 * fontChar.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */
#include "fontChar.hpp"

using namespace chip8::font;

FontChar::FontChar(char charCode, u8 *rowData)
{
	ReSetFont(charCode, 5, rowData[0], rowData[1], rowData[2], rowData[3], rowData[4]);
}

FontChar::FontChar()
{
	ReSetFont(0, 0, 0);
}

FontChar::~FontChar()
{

}

void FontChar::SetCharCode(char charCode)
{
	this->charCode = charCode;
}

void FontChar::SetRowData(u8 *rowData, u8 rowCount)
{
	this->rowData = rowData;
	this->rowCount = rowCount;
}

void FontChar::ReSetFont(char charCode, u8 rowCount, u8 data...)
{
	va_list args;
	va_start(args, rowCount);

	this->charCode = charCode;
	this->rowData = new u8[rowCount];
	this->rowCount = rowCount;
	for (u8 i = 0; i < rowCount; i++)
	{
		this->rowData[i] = va_arg(args, u8);
	}
	va_end(args);
}

u8 FontChar::GetCharCode()
{
	return this->charCode;
}

u8 FontChar::GetRowCount()
{
	return this->rowCount;
}

u8 FontChar::GetRow(u8 rowIndex)
{
	if (this->rowData != 0)
		return this->rowData[rowIndex % this->rowCount];
	else
		return 0;
}



