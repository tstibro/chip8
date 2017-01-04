#ifndef CHIP8_HPP_
#define CHIP8_HPP_
#include "chip8Types.hpp"

#ifdef CHIP8LIB_EXPORTS  
#define CHIP8LIB_API __declspec(dllexport)   
#else  
#define CHIP8LIB_API __declspec(dllimport)   
#endif  

namespace chip8 {
	namespace core {
		namespace memory
		{
			class RAM;
		}
	}
}

namespace chip8 {
	namespace core {
		namespace cpu
		{
			class CPU;
		}
	}
}

namespace chip8 {
	namespace core {
		namespace gpu
		{
			class GPU;
		}
	}
}

namespace chip8 {
	namespace adapter {
		class Chip8AudioAdapter;
		class Chip8VideoAdapter;
	}
}

namespace chip8 {
	namespace io {
		namespace input
		{
			class Keyboard;
		}
	}
}

namespace chip8 {
	namespace font
	{
		class Font;
	}
}

using namespace chip8::core::memory;
using namespace chip8::core::cpu;
using namespace chip8::core::gpu;
using namespace chip8::adapter;
using namespace chip8::io::input;
using namespace chip8::font;
using namespace std;

namespace chip8
{
	class CHIP8LIB_API Chip8
	{
	private:
		RAM *ram;
		CPU *cpu;
		GPU *gpu;
		u8 *gpuExchangeBuffer;
		Keyboard *keyboard;
		Chip8AudioAdapter *audioInterface;
		Chip8VideoAdapter *videoInterface;
		bool playAudio;
		Font *font;
		bool romLoaded;
		bool isRunning;

		void initialize();
		void updateTimers(long long dt); // Run the clock
		void updateAudio();
		void updateVideo();
	public:
		// Creates Chip8 emulator with enabled sound and video
		// Exception is thrown when either of the parameters are NULL
		Chip8(Chip8AudioAdapter *audioInterface, Chip8VideoAdapter *videoInterface);
		// Creates Chip8 emulator with only video enabled
		// Exception is thrown when videoInterface is NULL
		Chip8(Chip8VideoAdapter *videoInterface);
		// Creates Chip8 emulator with audio and video disabled. May be used for instruction debugging.
		Chip8();
		~Chip8();

		// Load Chip8 program to memory
		void LoadROM(char* romFilePath);
		// Update keboard's key state
		void UpdateInput(u8 keyCode, bool pressed);
		// Emulate 1 execution cycle
		// msPassed is number of milliseconds that have passed since previous cycle.
		void EmulateCycle(u32 msPassed);

		//void LoadNextInstruction();
		//Chip8Instruction GetInstructionInfo();
		//void ExecuteInstruction();
		static u32 GetDisplayWidth();
		static u32 GetDisplayHeight();
	};
}

#endif // CHIP8_HPP_

