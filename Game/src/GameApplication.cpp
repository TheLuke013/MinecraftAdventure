#include "GameApplication.h"

namespace Game
{
    GameApplication::GameApplication()
        : grassBlock(new Minecraft::Block("minecraft:grass_block", ""))
    {
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
