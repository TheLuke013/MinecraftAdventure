#ifndef BLOCK_H
#define BLOCK_H

#include "Minecraft/Core.h"

#include <string>

namespace Minecraft
{
	struct BlockTextures
	{
		std::string front;
		std::string back;
		std::string left;
		std::string right;
		std::string top;
		std::string bottom;
	};

	struct BlockProperties
	{
		std::string identifier;
		BlockTextures textures;
	};

	class MINECRAFT_API Block
	{
	public:
		Block(const std::string& identifier, BlockTextures& textures);
		~Block();

		BlockProperties& GetData();

	private:
		BlockProperties properties;
	};
}

#endif
