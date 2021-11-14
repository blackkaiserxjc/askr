
set(askr_meta_SRCS
    type_traits.h
)

add_library(askr_meta INTERFACE ${askr_meta_SRCS})
add_library(askr::meta ALIAS askr_meta)