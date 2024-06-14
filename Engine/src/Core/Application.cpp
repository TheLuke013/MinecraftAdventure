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
					static Vector3 pos = { 0.0f, 0.0f, 0.0f };
					DrawCube(pos, 2.0f, 2.0f, 2.0f, GREEN);
					DrawCubeWires(pos, 2.0f, 2.0f, 2.0f, BLACK);
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
			LOG_INFO(block->GetData().identifier + " was Registered");
		}
	}
}