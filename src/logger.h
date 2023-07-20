
#include "spdlog/spdlog.h"

#define INFO(...)    spdlog::info(__VA_ARGS__)
#define TRACE(...)   spdlog::trace(__VA_ARGS__)
#define WARN(...)    spdlog::warn(__VA_ARGS__)
#define ERROR(...)   spdlog::error(__VA_ARGS__)