#include "Engine/Core/Application.h"

#include <raylib.h>

namespace Engine
{
	Application::Application()
	{
		isRunning = true;

		InitWindow(1024, 600, "Engine");
	}

	Application::~Application()
	{
		CloseWindow();
	}

	void Application::Run()
	{
		OnReady();

		while (isRunning)
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