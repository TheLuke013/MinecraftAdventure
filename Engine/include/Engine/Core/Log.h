#ifndef ENGINE_LOG_H
#define ENGINE_LOG_H

#include "Engine/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Engine
{
	class ENGINE_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetLogger() { return logger; }

	private:
		static std::shared_ptr<spdlog::logger> logger;
	};

}

#define LOG_TRACE(...)		   ::Engine::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)		   ::Engine::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)		   ::Engine::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		   ::Engine::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_FATAL(...)		   ::Engine::Log::GetLogger()->critical(__VA_ARGS__)

#endif