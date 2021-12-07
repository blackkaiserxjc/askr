#pragma once

#include <spdlog/spdlog.h>

/** 日志相关宏 */
#define LOG_IMPL(logger, level, ...) (logger)->log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, level, __VA_ARGS__)

#define LOG_TRACE(logger, ...) LOG_IMPL(logger, spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(logger, ...) LOG_IMPL(logger, spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(logger, ...) LOG_IMPL(logger, spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(logger, ...) LOG_IMPL(logger, spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(logger, ...) LOG_IMPL(logger, spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(logger, ...) LOG_IMPL(logger, spdlog::level::critical, __VA_ARGS__)
