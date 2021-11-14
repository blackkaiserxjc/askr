#include <iostream>

#include <askr/utility/auto_timer.h>
#include <askr/utility/string.h>

namespace askr {

logger::logger()
    : logger_("AutoTimer")
{
}

void logger::operator()(std::string_view msg, const std::chrono::duration<double> &sec) const
{
    if (msg.empty())
    {
        return;
    }
    //KRLOG_DEBUG(logger_, "Profile") << "msg: " << msg << " in " << pretty_print(sec.count(), PrettyType::PRETTY_TIME, false);
}
} // namespace askr
