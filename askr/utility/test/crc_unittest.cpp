#include <boost/test/unit_test.hpp>

#include <askr/utility/crc.h>
#include <string_view>

constexpr uint32_t crc32(std::string_view str)
{
    askr::crc<32> crc;
    crc.update(str.data(), str.size());
    return crc.checksum();
    /*
    uint32_t crc = 0xffffffff;
    for (auto c : str)
        crc = askr::detail::crc_table<32>::update(crc, c);
    return crc ^ 0xffffffff;*/
}

BOOST_AUTO_TEST_SUITE(CRC)

BOOST_AUTO_TEST_CASE(CompileTimeTest)

{
    // BOOST_CHECK_EQUAL((crc32("123456789")), 0xCBF43926);
    static_assert(crc32("123456789") == 0xCBF43926);
}

BOOST_AUTO_TEST_SUITE_END()