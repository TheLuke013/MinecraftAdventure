#include "Engine/Core/Window.h"

namespace Engine
{
	Window::Window(const std::string& title, int width, int height)
	{
		properties.title = title;
		properties.width = width;
		properties.height = height;
	}

	Window::~Window()
	{
		
	}

	void Window::Init()
	{
		InitWindow(properties.width, properties.height, properties.title.c_str());
	}

	void Window::Close()
	{
		CloseWindow();
	}
}