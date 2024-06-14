#ifndef GAME_APPLICATION_H
#define GAME_APPLICATION_H

#include <Engine/Engine.h>
#include <Minecraft/Minecraft.h>

namespace Game
{
    class GameApplication : public Engine::Application
    {
    public:
        GameApplication();
        ~GameApplication();

        void OnReady() override;
        void OnUpdate() override;

    private:
        Minecraft::Block* grassBlock;
    };
}

#endif
