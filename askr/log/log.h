#pragma once

#include <string_view>

#include <fmt/format.h>
#include <source_location>
#include <spdlog/spdlog.h>

namespace askr {

enum class level
{
    trace = spdlog::level::trace,
    debug = spdlog::level::debug,
    info = spdlog::level::info,
    warn = spdlog::level::warn,
    error = spdlog::level::err,
    critical = spdlog::level::critical,
};

template <typename... Args>
inline void log(spdlog::source_loc location, level level, fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::log(location, static_cast<spdlog::level::level_enum>(level), fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void log(level level, fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::log(static_cast<spdlog::level::level_enum>(level), fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void trace(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::trace(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void debug(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::debug(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void info(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::info(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void warn(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::warn(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void error(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::error(fmt, std::forward<Args>(args)...);
}

template <typename... Args>
inline void critical(fmt::format_string<Args...> fmt, Args &&...args)
{
    spdlog::critical(fmt, std::forward<Args>(args)...);
}

template <typename T>
inline void log(spdlog::source_loc source, level level, T &&msg)
{
    spdlog::log(source, static_cast<spdlog::level::level_enum>(level), std::forward<T>(msg));
}

template <typename T>
inline void log(level level, T &&msg)
{
    spdlog::log(static_cast<spdlog::level::level_enum>(level), std::forward<T>(msg));
}

template <typename T>
inline void trace(T &&msg)
{
    spdlog::trace(std::forward<T>(msg));
}

template <typename T>
inline void debug(T &&msg)
{
    spdlog::debug(std::forward<T>(msg));
}

template <typename T>
inline void info(T &&msg)
{
    spdlog::info(std::forward<T>(msg));
}

template <typename T>
inline void warn(T &&msg)
{
    spdlog::warn(std::forward<T>(msg));
}

template <typename T>
inline void error(T &&msg)
{
    spdlog::error(std::forward<T>(msg));
}

template <typename T>
inline void critical(T &&msg)
{
    spdlog::critical(std::forward<T>(msg));
}

} // namespace askr

/** 日志相关宏 */
#define LOG_IMPL(logger, level, ...) (logger)->log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, level, __VA_ARGS__)

#define LOG_TRACE(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...) LOG_IMPL(spdlog::default_logger_raw(), spdlog::level::critical, __VA_ARGS__)
