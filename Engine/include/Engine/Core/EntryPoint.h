#ifndef ENTRY_POINT_H
#define ENTRY_POINT_H

#ifdef _WIN32

#include "Engine/Core/Application.h"

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Engine::CreateApplication();
	app->Run();
	delete app;

	return 0;
}

#endif

#endif