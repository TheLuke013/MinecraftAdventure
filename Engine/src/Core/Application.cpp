#include "Engine/Core/Application.h"

namespace Engine
{
	Application::Application()
		: window(new Window("Minecraft Adventure", 1024, 600))
	{
		isRunning = true;

		Log::Init("logs.txt");
		LOG_INFO("Engine Initialized");

		window->Init();
	}

	Application::~Application()
	{
		window->Close();

		LOG_INFO("Engine Shutdown");
		Log::Shutdown();

		delete window;
	}

	void Application::Run()
	{
		OnReady();

		while (isRunning && !window->IsClosed())
		{
			BeginDrawing();
			ClearBackground(RAYWHITE);
			EndDrawing();
			OnUpdate(); //updates client-application
		}
	}

	void Application::Quit()
	{
		isRunning = false;
	}
}