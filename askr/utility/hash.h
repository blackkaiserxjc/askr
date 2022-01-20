#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

#include <askr/utility/crc.h>

namespace askr {
/**
 *  计算字符串的哈希值
 * @param sv 字符串
 * @return   哈希值
 */
inline constexpr std::uint32_t hash_str(std::string_view sv)
{
    crc32_type result;
    result.update(sv);
    return result.checksum();
}
} // namespace askr
