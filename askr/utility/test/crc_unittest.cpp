#include <boost/test/unit_test.hpp>

#include <askr/utility/crc.h>
#include <string_view>

constexpr uint32_t crc32(std::string_view str)
{
    askr::crc<32> crc;
    crc.update(str);
    crc.update(12345678);
    crc.update(3.14f);
    return crc.checksum();
}

BOOST_AUTO_TEST_SUITE(CRC)

BOOST_AUTO_TEST_CASE(CompileTimeTest)
{
    // BOOST_CHECK_EQUAL((crc32("123456789")), 0xCBF43926);
    static_assert(crc32("123456789") == 0xCBF43926);
}

BOOST_AUTO_TEST_SUITE_END()