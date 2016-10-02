/*
 * drawSpriteInstruction.hpp
 *
 *  Created on: Aug 1, 2016
 *      Author: Tomas Stibrany
 */

#ifndef CORE_CPU_INSTRUCTIONS_DRAWSPRITEINSTRUCTION_HPP_
#define CORE_CPU_INSTRUCTIONS_DRAWSPRITEINSTRUCTION_HPP_
#include "../../../chip8Types.hpp"
#include "iinstruction.hpp"

namespace chip8 { namespace core { namespace cpu
{
	class CPU;
}}}

namespace chip8 { namespace core { namespace cpu { namespace instructions
{

	class DrawSpriteInstruction : public IInstruction
	{
	private:
		u8 xCoordinateRegister;
		u8 yCoordinateRegister;
		u8 spriteHeight;
		CPU *cpu;
	public:
		DrawSpriteInstruction(u8 xCoordinateRegister, u8 yCoordinateRegister, u8 spriteHeight, CPU *cpu);
		virtual ~DrawSpriteInstruction();
		virtual void Execute();
	};

}}}}




#endif /* CORE_CPU_INSTRUCTIONS_DRAWSPRITEINSTRUCTION_HPP_ */
