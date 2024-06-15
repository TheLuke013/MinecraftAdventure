#include "Engine/Minecraft/EngineBlock.h"

namespace Engine
{
	EngineBlock::EngineBlock(Minecraft::Block* block)
	{
        textures.front = LoadTexture(block->GetData().textures.front.c_str());;
        textures.back = LoadTexture(block->GetData().textures.back.c_str());;
        textures.left = LoadTexture(block->GetData().textures.left.c_str());;
        textures.right = LoadTexture(block->GetData().textures.right.c_str());;
        textures.top = LoadTexture(block->GetData().textures.top.c_str());;
        textures.bottom = LoadTexture(block->GetData().textures.bottom.c_str());

        if (textures.front.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.front);
        if (textures.back.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.back);
        if (textures.left.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.left);
        if (textures.right.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.right);
        if (textures.top.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.top);
        if (textures.bottom.id == 0) LOG_ERROR("Failed to load texture: " + block->GetData().textures.bottom);
	}

	EngineBlock::~EngineBlock()
	{
        UnloadTexture(textures.front);
        UnloadTexture(textures.back);
        UnloadTexture(textures.left);
        UnloadTexture(textures.right);
        UnloadTexture(textures.top);
        UnloadTexture(textures.bottom);
	}

	void EngineBlock::Render(Vector3 position, Color color)
	{
        static Rectangle source = { 0, 16, 16, 16 };

        float x = position.x;
        float y = position.y;
        float z = position.z;
        float texWidth = 16.0f;
        float texHeight = 16.0f;
        float width = 1.0f;
        float height = 1.0f;
        float length = 1.0f;

        rlBegin(RL_QUADS);
        rlColor4ub(color.r, color.g, color.b, color.a);

        //front face
        rlSetTexture(textures.front.id);
        rlNormal3f(0.0f, 0.0f, 1.0f);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
        rlSetTexture(0);

        //back face
        rlSetTexture(textures.back.id);
        rlNormal3f(0.0f, 0.0f, -1.0f);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
        rlSetTexture(0);

        //top face
        rlSetTexture(textures.top.id);
        rlNormal3f(0.0f, 1.0f, 0.0f);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
        rlSetTexture(0);

        //bottom face
        rlSetTexture(textures.bottom.id);
        rlNormal3f(0.0f, -1.0f, 0.0f);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
        rlSetTexture(0);

        //right face
        rlSetTexture(textures.right.id);
        rlNormal3f(1.0f, 0.0f, 0.0f);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z - length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z - length / 2);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x + width / 2, y + height / 2, z + length / 2);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x + width / 2, y - height / 2, z + length / 2);
        rlSetTexture(0);

        //left face
        rlSetTexture(textures.left.id);
        rlNormal3f(-1.0f, 0.0f, 0.0f);
        rlTexCoord2f(source.x / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z - length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, (source.y + source.height) / texHeight);
        rlVertex3f(x - width / 2, y - height / 2, z + length / 2);
        rlTexCoord2f((source.x + source.width) / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z + length / 2);
        rlTexCoord2f(source.x / texWidth, source.y / texHeight);
        rlVertex3f(x - width / 2, y + height / 2, z - length / 2);
        rlSetTexture(0);

        rlEnd();
	}
}