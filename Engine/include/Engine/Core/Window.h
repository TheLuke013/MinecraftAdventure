#ifndef WINDOW_H
#define WINDOW_H

#include <raylib.h>
#include <string>

#include "Engine/Core/Core.h"

namespace Engine
{
	struct WindowProperties
	{
		std::string title;
		int width;
		int height;
	};

	class ENGINE_API Window
	{
	public:
		Window(const std::string& title, int width, int height);
		~Window();

		void Init();
		void Close();
		bool IsClosed() { return WindowShouldClose(); }

	private:
		WindowProperties properties;
	};
}

#endif
