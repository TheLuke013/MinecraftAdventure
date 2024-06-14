#include "Engine/Core/Log.h"

namespace Engine
{
	std::ofstream Log::logFile;
    std::string Log::logFilePath;
    const char* Log::textColorTable[TEXT_COLOR_COUNT] = {
        "\x1b[30m",  // TEXT_COLOR_BLACK
        "\x1b[31m",  // TEXT_COLOR_RED
        "\x1b[32m",  // TEXT_COLOR_GREEN
        "\x1b[33m",  // TEXT_COLOR_YELLOW
        "\x1b[34m",  // TEXT_COLOR_BLUE
        "\x1b[35m",  // TEXT_COLOR_MAGENTA
        "\x1b[36m",  // TEXT_COLOR_CYAN
        "\x1b[37m",  // TEXT_COLOR_WHITE
        "\x1b[90m",  // TEXT_COLOR_BRIGHT_BLACK
        "\x1b[91m",  // TEXT_COLOR_BRIGHT_RED
        "\x1b[92m",  // TEXT_COLOR_BRIGHT_GREEN
        "\x1b[93m",  // TEXT_COLOR_BRIGHT_YELLOW
        "\x1b[94m",  // TEXT_COLOR_BRIGHT_BLUE
        "\x1b[95m",  // TEXT_COLOR_BRIGHT_MAGENTA
        "\x1b[96m",  // TEXT_COLOR_BRIGHT_CYAN
        "\x1b[97m"   // TEXT_COLOR_BRIGHT_WHITE
    };
}