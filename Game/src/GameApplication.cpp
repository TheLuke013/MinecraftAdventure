#include "GameApplication.h"

namespace Game
{
    GameApplication::GameApplication()
        : grassBlock(nullptr)
    {
        grassTextures = 
        { 
            "assets/textures/blocks/grass_side.png",
            "assets/textures/blocks/grass_side.png",
            "assets/textures/blocks/grass_side.png",
            "assets/textures/blocks/grass_side.png",
            "assets/textures/blocks/grass_top.png",
            "assets/textures/blocks/dirt.png" 
        };
        grassBlock = new Minecraft::Block("minecraft:grass_block", grassTextures);
        Minecraft::Register::RegisterBlock(grassBlock);
    }

    GameApplication::~GameApplication()
    {
    }

    void GameApplication::OnReady()
    {
    }

    void GameApplication::OnUpdate()
    {

    }
}

Engine::Application* Engine::CreateApplication()
{
    return new Game::GameApplication();
}
