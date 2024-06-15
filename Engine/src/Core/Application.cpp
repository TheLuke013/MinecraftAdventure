#include "Engine/Core/Application.h"

namespace Engine
{
	Application::Application()
		: window("Minecraft Adventure", 1024, 600)
	{
		isRunning = true;

		Log::Init("logs.txt");
		LOG_INFO("Engine Initialized");

		window.Init();
	}

	Application::~Application()
	{
		window.Close();

		LOG_INFO("Engine Shutdown");
		Log::Shutdown();
	}

	void Application::Run()
	{
		RegisterMinecraftContents();

		DisableCursor();
		SetTargetFPS(60);

		OnReady();

		while (isRunning && !window.IsClosed())
		{
			camera.Update();
			OnUpdate(); //updates client-application

			BeginDrawing();

				ClearBackground(SKYBLUE);

				camera.BeginCamera();
					for (int x = 0; x <= 16; x++)
					{
						for (int y = 0; y <= 16; y++)
						{
							for (int z = 0; z <= 16; z++)
							{
								minecraftContents.blocks[0]->Render({ (float)x, (float)y, (float)z }, WHITE);
							}
						}
					}
				camera.EndCamera();

			EndDrawing();
		}
	}

	void Application::Quit()
	{
		isRunning = false;
	}

	void Application::RegisterMinecraftContents()
	{
		//Register Blocks
		for (const auto& block : Minecraft::Register::GetRegisteredBlocks())
		{
			minecraftContents.blocks.push_back(new EngineBlock(block));
			LOG_INFO(block->GetData().identifier + " was Registered");
		}
	}
}