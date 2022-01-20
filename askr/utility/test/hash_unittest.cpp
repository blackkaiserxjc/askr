#include <boost/test/unit_test.hpp>

#include <askr/utility/hash.h>
#include <askr/utility/murmurhash.h>

BOOST_AUTO_TEST_SUITE(Hash)

BOOST_AUTO_TEST_CASE(BasicTestCase)
{
    BOOST_CHECK_EQUAL(askr::hash_str("42"), 0x3224B088);
    BOOST_CHECK_EQUAL(askr::hash_str("hello world"), 0x0D4A1185);

    static_assert(askr::hash_str("42") == 0x3224B088);
    static_assert(askr::hash_str("hello world") == 0x0D4A1185);
}

BOOST_AUTO_TEST_CASE(MurmurHashTestCase)
{
    std::string text = "42";
    BOOST_CHECK_EQUAL(MurmurHash(text.data(), static_cast<int>(text.size()), 0), askr::murmur_hash{}(text));
}

BOOST_AUTO_TEST_SUITE_END()
