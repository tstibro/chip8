/*
 * programLoader.hpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_MEMORY_PROGRAMLOADER_HPP_
#define CORE_MEMORY_PROGRAMLOADER_HPP_
#include "../memory/ram.hpp"
#include <fstream>

namespace chip8 { namespace core { namespace memory
{

	class ProgramLoader
	{
	private:
		u32 getFileSize(std::ifstream *fileStream);
	public:
		void LoadTo(RAM *ram, char *fileName);
	};

}}}



#endif /* CORE_MEMORY_PROGRAMLOADER_HPP_ */
