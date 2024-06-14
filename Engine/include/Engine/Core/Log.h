#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>

namespace Engine
{
	enum TextColor
	{
		TEXT_COLOR_BLACK,
		TEXT_COLOR_RED,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_YELLOW,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_MAGENTA,
		TEXT_COLOR_CYAN,
		TEXT_COLOR_WHITE,
		TEXT_COLOR_BRIGHT_BLACK,
		TEXT_COLOR_BRIGHT_RED,
		TEXT_COLOR_BRIGHT_GREEN,
		TEXT_COLOR_BRIGHT_YELLOW,
		TEXT_COLOR_BRIGHT_BLUE,
		TEXT_COLOR_BRIGHT_MAGENTA,
		TEXT_COLOR_BRIGHT_CYAN,
		TEXT_COLOR_BRIGHT_WHITE,
		TEXT_COLOR_COUNT
	};

	class Log
	{
	public:
		static void Init(const std::string& logFilePath)
		{
			Log::logFilePath = logFilePath;
			_ClearLogFile();
			logFile.open(logFilePath, std::ios::out | std::ios::app);
		}

		static void Shutdown()
		{
			if (logFile.is_open())
			{
				logFile.close();
			}
		}

		template <typename ...Args>
		static void Trace(const std::string& prefix, const std::string& msg, Args... args)
		{
			_Log(prefix, msg, TEXT_COLOR_GREEN, args...);
		}

		template <typename ...Args>
		static void Info(const std::string& prefix, const std::string& msg, Args... args)
		{
			_Log(prefix, msg, TEXT_COLOR_WHITE, args...);
		}

		template <typename ...Args>
		static void Warn(const std::string& prefix, const std::string& msg, Args... args)
		{
			_Log(prefix, msg, TEXT_COLOR_YELLOW, args...);
		}

		template <typename ...Args>
		static void Error(const std::string& prefix, const std::string& msg, Args... args)
		{
			_Log(prefix, msg, TEXT_COLOR_RED, args...);
		}

		template <typename ...Args>
		static void Fatal(const std::string& prefix, const std::string& msg, Args... args)
		{
			_Log(prefix, msg, TEXT_COLOR_BRIGHT_RED, args...);
		}

	private:
		static std::ofstream logFile;
		static std::string logFilePath;
		static const char* textColorTable[TEXT_COLOR_COUNT];

		template <typename ...Args>
		static void _Log(const std::string& prefix, const std::string& msg, TextColor textColor, Args... args)
		{
			std::string formattedMessage = prefix + msg;

			if (logFile.is_open())
			{
				logFile << formattedMessage << std::endl;
				logFile.flush();
			}

			printf("%s\n", formattedMessage.c_str());
		}

		static void _ClearLogFile()
		{
			std::ofstream clearFile(logFilePath, std::ios::out | std::ios::trunc);
			if (clearFile.is_open())
			{
				clearFile.close();
			}
		}
	};
}

#define LOG_TRACE(msg, ...) Engine::Log::Trace("ENGINE TRACE: ", msg, ##__VA_ARGS__);
#define LOG_INFO(msg, ...) Engine::Log::Info("ENGINE INFO: ", msg, ##__VA_ARGS__);
#define LOG_WARN(msg, ...) Engine::Log::Warn("ENGINE WARN: ", msg, ##__VA_ARGS__);
#define LOG_ERROR(msg, ...) Engine::Log::Error("ENGINE ERROR: ", msg, ##__VA_ARGS__);
#define LOG_FATAL(msg, ...) Engine::Log::Fatal("ENGINE FATAL: ", msg, ##__VA_ARGS__);

#endif
