#pragma once

#include <spdlog/spdlog.h>
#include <string_view>

namespace askr {

class logger
{
public:
    std::string name() const
    {
        return logger_->name();
    }

    void set_level(spdlog::level::level_enum level)
    {
        logger_->set_level(level);
    }

    spdlog::level::level_enum level() const
    {
        return logger_->level();
    }

protected:
    logger(std::shared_ptr<spdlog::logger> logger);

private:
    std::shared_ptr<spdlog::logger> logger_;
};

} // namespace askr