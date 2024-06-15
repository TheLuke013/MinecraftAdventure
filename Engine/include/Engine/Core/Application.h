#ifndef APPLICATION_H
#define APPLICATION_H

#include "Engine/Core/Core.h"
#include "Engine/Core/Log.h"
#include "Engine/Core/Window.h"
#include "Engine/Renderer/Camera.h"

#include "Engine/Minecraft/EngineBlock.h"

#include <Minecraft/Minecraft.h>

namespace Engine
{
	struct MinecraftContents
	{
		std::vector<EngineBlock*> blocks;
	};

	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void OnReady() = 0;
		virtual void OnUpdate() = 0;

		void Run();
		void Quit();

	private:
		bool isRunning;
		Window window;
		Camera camera;
		MinecraftContents minecraftContents;

		void RegisterMinecraftContents();
	};

	Application* CreateApplication();
}

#endif