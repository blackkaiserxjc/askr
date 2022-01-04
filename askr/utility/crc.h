#pragma once

#include <askr/utility/detail/crc_table.h>

namespace askr {

template <std::size_t Bits>
class crc
{
public:
    using value_type = typename detail::crc_table<Bits>::value_type;

    /**
     * 构造函数
     */
    constexpr crc() noexcept
        : rem_{detail::crc_table<Bits>::init_rem}
    {
    }

    /**
     * 析构函数
     */
    ~crc() noexcept = default;

    /**
     * @brief 重置.
     */
    void reset()
    {
        rem_ = detail::crc_table<Bits>::init_rem;
    }

    /**
     * 更新
     * @param data 数据
     * @param size 数据大小
     */
    constexpr void update(void const *data, std::size_t size)
    {
        auto const *start = static_cast<const std::uint8_t *>(data);
        auto const *end = start + size;
        for (auto p = start; p < end; ++p)
        {
            rem_ = detail::crc_table<Bits>::update(rem_, *p);
        }
    }

    constexpr void update(std::string_view str)
    {
        for (auto c : str)
        {
            rem_ = detail::crc_table<Bits>::update(rem_, c);
        }
    }

    /**
     * 获取校验和
     */
    constexpr value_type checksum() const
    {
        return detail::crc_table<Bits>::finalize(rem_);
    }

private:
    value_type rem_;
};

} // namespace askr