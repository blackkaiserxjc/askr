#include <boost/test/unit_test.hpp>
#include <string>

#include <askr/log/log.h>

BOOST_AUTO_TEST_SUITE(Log)

BOOST_AUTO_TEST_CASE(MacroTestCase)
{
    LOG_TRACE("MacroTestCase: This is a trace log");
    LOG_INFO("MacroTestCase: This is a info log");
    LOG_DEBUG("MacroTestCase: This is a debug log");
    LOG_WARN("MacroTestCase: This is a warn log");
    LOG_ERROR("MacroTestCase: This is an error log");
    LOG_CRITICAL("MacroTestCase: This is a critical log");

    LOG_TRACE("MacroTestCase: This is a trace log: {}", "hello world");
    LOG_INFO("MacroTestCase: This is a info log: {}", "hello world");
    LOG_DEBUG("MacroTestCase: This is a debug log: {}", "hello world");
    LOG_WARN("MacroTestCase: This is a warn log: {}", "hello world");
    LOG_ERROR("MacroTestCase: This is an error log: {}", "hello world");
    LOG_CRITICAL("MacroTestCase: This is a critical log: {}", "hello world");
}

BOOST_AUTO_TEST_CASE(WarpperTestCase)
{
    spdlog::default_logger_raw()->set_pattern("[%Y-%m-%d %T.%e][%t][%l] %v");

    askr::log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, askr::level::trace, "WarpperTestCase: This is a trace log");
    askr::log(spdlog::source_loc{__FILE__, __LINE__, __FUNCTION__}, askr::level::info, "WarpperTestCase: This is a info log: {}", "hello world");

    askr::log(askr::level::trace, "WarpperTestCase: This is a trace log");
    askr::log(askr::level::info, "WarpperTestCase: This is a info log");
    askr::log(askr::level::debug, "WarpperTestCase: This is a debug log");
    askr::log(askr::level::warn, "WarpperTestCase: This is a warn log");
    askr::log(askr::level::error, "This is an error log");
    askr::log(askr::level::critical, "This is a critical log");

    askr::log(askr::level::trace, "WarpperTestCase: This is a trace log: {}", "hello world");
    askr::log(askr::level::info, "WarpperTestCase: This is a info log: {}", "hello world");
    askr::log(askr::level::debug, "WarpperTestCase: This is a debug log: {}", "hello world");
    askr::log(askr::level::warn, "WarpperTestCase: This is a warn log: {}", "hello world");
    askr::log(askr::level::error, "WarpperTestCase: This is an error log: {}", "hello world");
    askr::log(askr::level::critical, "WarpperTestCase: This is a critical log: {}", "hello world");

    askr::trace("WarpperTestCase: This is a trace log");
    askr::info("WarpperTestCase: This is a info log");
    askr::debug("WarpperTestCase: This is a debug log");
    askr::warn("WarpperTestCase: This is a warn log");
    askr::error("WarpperTestCase: This is an error log");
    askr::critical("WarpperTestCase: This is a critical log");

    askr::trace("WarpperTestCase: This is a trace log: {}", "hello world");
    askr::info("WarpperTestCase: This is a info log: {}", "hello world");
    askr::debug("WarpperTestCase: This is a debug log: {}", "hello world");
    askr::warn("WarpperTestCase: This is a warn log: {}", "hello world");
    askr::error("WarpperTestCase: This is an error log: {}", "hello world");
    askr::critical("WarpperTestCase: This is a critical log: {}", "hello world");
}

BOOST_AUTO_TEST_SUITE_END()