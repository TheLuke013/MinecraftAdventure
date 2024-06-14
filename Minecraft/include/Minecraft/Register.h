#ifndef REGISTER_H
#define REGISTER_H

#include "Minecraft/Core.h"
#include "Minecraft/Block.h"

#include <vector>

namespace Minecraft
{
	class MINECRAFT_API Register
	{
	public:
		static void RegisterBlock(Block* block);

		static std::vector<Block*>& GetRegisteredBlocks();

	private:
		static std::vector<Block*> registeredBlocks;
	};
}

#endif
