find_package(spdlog CONFIG REQUIRED)
set(arkr_log_SRCS
    log.h
)

add_library(askr_log INTERFACE ${arkr_log_SRCS})
add_library(askr::log ALIAS askr_log)

if(ENABLE_TESTING)
    add_subdirectory(test)
endif()