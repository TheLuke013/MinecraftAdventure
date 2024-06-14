#include "GameApplication.h"

namespace Game
{
    GameApplication::GameApplication()
    {
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
