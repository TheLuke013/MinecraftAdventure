#include "Minecraft/Block.h"

namespace Minecraft
{
	Block::Block(const std::string& identifier, const std::string& texturePath)
	{
		properties.identifier = identifier;
		properties.texturePath = texturePath;
	}

	Block::~Block()
	{
	}

	BlockProperties& Block::GetData()
	{
		return properties;
	}
}