namespace askr {
namespace detail {

enum class sink_type
{
    stdout_sink_st,
    stdout_sink_mt,
    sterr_sink_st,
    sterr_sink_mt,
    stdout_color_sink_st,
    stdout_color_sink_mt,
    stderr_color_sink_st,
    stderr_color_sink_mt,
    basic_file_sink_st,
    basic_file_sink_mt,
    rotating_file_sink_st,
    rotating_file_sink_mt,
    daily_file_sink_st,
    daily_file_sink_mt,
    null_sink_st,
    null_sink_mt,
    syslog_sink_st,
    syslog_sink_mt,
};
} // namespace detail
} // namespace askr
