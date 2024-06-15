#ifndef ENGINE_BLOCK_H
#define ENGINE_BLOCK_H

#include <raylib.h>
#include <rlgl.h>
#include <string>

#include "Engine/Core/Core.h"
#include "Engine/Core/Log.h"

#include <Minecraft/Minecraft.h>

namespace Engine
{
	struct BlockFaceVisibility
	{
		bool front = true;
		bool back = true;
		bool left = true;
		bool right = true;
		bool top = true;
		bool bottom = true;
	};

	struct BlockTextures
	{
		Texture2D front;
		Texture2D back;
		Texture2D left;
		Texture2D right;
		Texture2D top;
		Texture2D bottom;
	};

	class ENGINE_API EngineBlock
	{
	public:
		EngineBlock(Minecraft::Block* block);
		~EngineBlock();

		void Render(Vector3 position, Color color);

	private:
		BlockFaceVisibility visibility;
		BlockTextures textures;

	};
}

#endif
