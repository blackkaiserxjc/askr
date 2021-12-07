#include <askr/log/logger.h>

namespace askr {

logger::logger(std::shared_ptr<spdlog::logger> logger)
    : logger_(logger)
{
    static constexpr std::string_view default_logger_format = "[%Y-%m-%d %T.%e][%t][%l][%n] [%g:%#] %v";
    logger_->set_pattern(default_logger_format);
    logger_->set_level(spdlog::level::trace);
    logger_->flush_on(spdlog::level::critical);
}

} // namespace askr
