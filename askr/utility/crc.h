#pragma once

#include <climits>

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
     * 整数更新
     * @param value 数据
     */
    template <typename T, typename std::enable_if_t<std::is_integral<T>::value, int> = 0>
    constexpr void update(T value) noexcept
    {
        [&]<std::size_t... N>(std::index_sequence<N...>)
        {
            ((rem_ = detail::crc_table<Bits>::update(rem_, (value >> N * CHAR_BIT) & 0xff)), ...);
        }
        (std::make_index_sequence<sizeof(T)>{});
    }

    /**
     * 浮点数更新
     * @param value 数据
     */
    constexpr void update(float value) noexcept
    {
        union
        {
            float f;
            uint32_t i;
        } u{value};
        update(static_cast<uint32_t>(u.i));
    }

    constexpr void update(double value) noexcept
    {
        union
        {
            double d;
            uint64_t i;
        } u{value};
        update(static_cast<uint64_t>(u.i));
    }

    /**
     * 字符串更新
     * @param str 字符串
     */
    constexpr void update(std::string_view str) noexcept
    {
        for (auto c : str)
        {
            update(c);
        }
    }

    /**
     * 更新
     * @param data 数据
     * @param size 数据大小
     */
    void update(void const *data, std::size_t size)
    {
        auto const *start = static_cast<const std::uint8_t *>(data);
        auto const *end = start + size;
        for (auto p = start; p < end; ++p)
        {
            rem_ = detail::crc_table<Bits>::update(rem_, *p);
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