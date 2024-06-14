#ifndef APPLICATION_H
#define APPLICATION_H

#include "Engine/Core/Core.h"

namespace Engine
{
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
	};

	Application* CreateApplication();
}

#endif