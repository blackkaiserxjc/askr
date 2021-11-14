find_package(Boost REQUIRED COMPONENTS atomic date_time regex system thread filesystem log_setup log unit_test_framework)
find_package(fmt CONFIG REQUIRED)
find_package(Threads REQUIRED)

set(askr_utility_unittest_SRCS
    hash_unittest.cpp
    random_unittest.cpp
    string_unittest.cpp
    uri_unittest.cpp
    unittest_main.cpp
    ioc_unittest.cpp
)

add_executable(askr_utility_unittest ${askr_utility_unittest_SRCS})

target_link_libraries(askr_utility_unittest
    askr::utility
    fmt::fmt
    Boost::log_setup
    Boost::log
    Boost::atomic
    Boost::date_time
    Boost::filesystem
    Boost::regex
    Boost::system
    Boost::thread
    Boost::unit_test_framework
    Threads::Threads
)