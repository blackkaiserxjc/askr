cmake_minimum_required(VERSION 3.5)

if (POLICY CMP0054)
    cmake_policy(SET CMP0054 NEW)
endif()

if (POLICY CMP0057)
    cmake_policy(SET CMP0057 NEW)
endif()

project(askr LANGUAGES CXX)

#默认debug
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()

# 开启测试
enable_testing()

# 平台相关
if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /EHs /DEBUG /std:c++latest")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /GS /Od /MTd /bigobj")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Gy /MT /O2 -DNDEBUG /bigobj")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO /DEBUG")
    add_definitions(-D_WIN32_WINNT=0x0601 -DBOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE -D_SCL_SECURE_NO_WARNINGS -D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS -D_CRT_SECURE_NO_WARNINGS -D_DISABLE_EXTENDED_ALIGNED_STORAGE)
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -g")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wvolatile -Wno-dev")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2 -DNDEBUG -Wvolatile -Wno-dev")
    add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
endif ()

# 添加自定义模块路径
set(CMAKE_MODULE_PATH
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake"
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules"
    ${CMAKE_MODULE_PATH}
)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_subdirectory(askr)