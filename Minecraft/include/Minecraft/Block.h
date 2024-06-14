#ifndef BLOCK_H
#define BLOCK_H

#include "Minecraft/Core.h"

#include <string>

namespace Minecraft
{
	struct BlockPosition
	{
		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;
	};

	struct BlockProperties
	{
		std::string texturePath;
		std::string identifier;
		BlockPosition position;
	};

	class MINECRAFT_API Block
	{
	public:
		Block(const std::string& identifier, const std::string& texturePath);
		~Block();

		BlockProperties& GetData();

	private:
		BlockProperties properties;
	};
}

#endif
