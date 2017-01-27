/*
 * programLoader.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Tomas Stibrany
 */
#include "programLoader.hpp"
#include <fstream>

using namespace chip8::core::memory;
using namespace std;

void ProgramLoader::LoadTo(RAM *ram,const char *fileName)
{
	ifstream programRom;
	programRom.open(fileName, ios::binary | ios::in);

	u32 ramProgramSegmentSize = ram->GetProgramSegmentEndAddress() - ram->GetProgramSegmentStartAddress();
	u32 programSize = getFileSize(&programRom);
	if (programSize < ramProgramSegmentSize)
	{
		u16 ramAddress = ram->GetProgramSegmentStartAddress();
		char c;
		while(!programRom.eof())
		{
			programRom.read(&c, 1);
			ram->Write(ramAddress, (u8)c);
			ramAddress++;
		}
	}
	programRom.close();
}

u32 ProgramLoader::getFileSize(ifstream *fileStream)
{
	fileStream->seekg(0, fileStream->end);
	i32 FileSize = (i32)fileStream->tellg();
	fileStream->seekg( 0, fileStream->beg);

	return (u32)FileSize;
}




