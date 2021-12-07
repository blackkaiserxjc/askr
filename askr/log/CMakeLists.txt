find_package(spdlog CONFIG REQUIRED) 
set(arkr_log_SRCS
    config.h
    config.cpp
    logging.h
)

add_library(askr_log ${arkr_log_SRCS})
add_library(askr::log ALIAS askr_log)
