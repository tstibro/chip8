/*
 * fontLoader.hpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Tomas Stibrany
 */

#ifndef FONT_FONTLOADER_HPP_
#define FONT_FONTLOADER_HPP_
#include "../chip8Types.hpp"

namespace chip8 {
	namespace core {
		namespace memory {
			class RAM;
		}
	}
}

namespace chip8 {
	namespace font {
		class Font;
	}
}

using namespace chip8::core::memory;
using namespace chip8::font;

namespace chip8 { namespace font
{

	class FontLoader
	{
	private:
	public:
		FontLoader();
		~FontLoader();
		void LoadTo(RAM *ram, Font *font);
	};

}}




#endif /* FONT_FONTLOADER_HPP_ */
