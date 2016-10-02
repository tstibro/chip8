/*
 * defaultFont.hpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */

#ifndef FONT_TYPES_FONT_HPP_
#define FONT_TYPES_FONT_HPP_
#include "../chip8Types.hpp"
#include "fontChar.hpp"

using namespace chip8::font;

namespace chip8 { namespace font
{

	// This is a default font which
    // has only limited set of characters.
    //
    // Characters:
    // 0 - 9
    // A - F
	class Font
	{
	private:
		FontChar *characters;
		u8 characterCount;

		void initialize();
	public:
		Font();
		virtual ~Font();
		virtual u8 GetCharacterCount();
		// Returns hex character data.
		virtual FontChar *GetCharacterByCode(char charCode);
		virtual FontChar *GetCharacterByIndex(u8 index);
	};

}}




#endif /* FONT_TYPES_FONT_HPP_ */
