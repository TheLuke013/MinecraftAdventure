#include "Engine/Core/Application.h"

namespace Engine
{
	Application::Application()
		: window("Minecraft Engine", 1024, 600)
	{
		isRunning = true;
		window.Init();
	}

	Application::~Application()
	{
		window.Close();
	}

	void Application::Run()
	{
		OnReady();

		while (isRunning && !window.IsClosed())
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