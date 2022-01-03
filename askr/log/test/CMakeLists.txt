find_package(Boost REQUIRED COMPONENTS atomic date_time regex system thread filesystem unit_test_framework)
find_package(Threads REQUIRED)
find_package(spdlog CONFIG REQUIRED)

set(askr_log_unittest_SRCS
    log_unittest.cpp
    unittest_main.cpp
)

add_executable(askr_log_unittest ${askr_log_unittest_SRCS})

target_link_libraries(askr_log_unittest
    askr::log
    spdlog::spdlog_header_only
    Boost::atomic
    Boost::date_time
    Boost::filesystem
    Boost::regex
    Boost::system
    Boost::thread
    Boost::unit_test_framework
    Threads::Threads
)