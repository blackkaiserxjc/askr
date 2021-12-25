find_package(Boost REQUIRED)
find_package(fmt CONFIG REQUIRED)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${FMT_INCLUDE_DIRS})

set(utility_SRCS
	base64.h
	base64.cpp
	expected.h
	hash.h
	ioc_container.h
	ioc_container.cpp
	murmurhash.h
	murmurhash.cpp
	random.h
	random.cpp
	span.h
	string.h
	string.cpp
	uri.h
	uri.cpp
)

set(utility_detail_SRCS
	detail/string.h
	detail/ioc_container.h
	detail/base64.h
	detail/base64.cpp
)

add_library(askr_utility
	${utility_SRCS}
	${utility_detail_SRCS}
)

add_library(askr::utility ALIAS askr_utility)

target_link_libraries(askr_utility
	PRIVATE
	fmt::fmt
)
