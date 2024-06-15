#include "Minecraft/Block.h"

namespace Minecraft
{
	Block::Block(const std::string& identifier, BlockTextures& textures)
	{
		properties.identifier = identifier;
		properties.textures.front = textures.front;
		properties.textures.back = textures.back;
		properties.textures.left = textures.left;
		properties.textures.right = textures.right;
		properties.textures.top = textures.top;
		properties.textures.bottom = textures.bottom;
	}

	Block::~Block()
	{
	}

	BlockProperties& Block::GetData()
	{
		return properties;
	}
}