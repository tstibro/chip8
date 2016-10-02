/*
 * fontChar.hpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */

#ifndef FONT_FONTCHAR_HPP_
#define FONT_FONTCHAR_HPP_
#include "../chip8Types.hpp"
#include <cstdarg>

namespace chip8 { namespace font
{

	class FontChar
	{
	private:
		char charCode;
		u8 rowCount;
		u8 *rowData;
	public:
		//Constructor. This creates a character of height 5
		FontChar(char charCode, u8 *rowData);
		//Default Constructor
		FontChar();
		~FontChar();

		void SetCharCode(char charCode);
		void SetRowData(u8 *rowData, u8 rowCount);
		void ReSetFont(char charCode, u8 rowCount,u8 data...);

		u8 GetCharCode();
		u8 GetRowCount();
		// Get Row data. rowIndex 0 is top row.
		u8 GetRow(u8 rowIndex);
	};

}}


#endif /* FONT_FONTCHAR_HPP_ */
