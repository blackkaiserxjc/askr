set(arkr_meta_unittest_SRCS
    function_traits_unittest.cpp
    unittest_main.cpp
)

add_executable(ask_meta_unittest ${arkr_meta_unittest_SRCS})

target_link_libraries(ask_meta_unittest
    askr::meta
)