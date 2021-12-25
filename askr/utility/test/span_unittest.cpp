#include <boost/test/unit_test.hpp>

#include <askr/utility/span.h>

BOOST_AUTO_TEST_SUITE(SpanTest)

template <class T>
class range
{
public:
    T *data()
    {
        return &v_[0];
    }

    std::size_t size() const
    {
        return 4;
    }

private:
    T v_[4];
};

BOOST_AUTO_TEST_CASE(Extent)
{
    BOOST_CHECK_EQUAL(askr::span<int>::extent, askr::dynamic_extent);
    BOOST_CHECK_EQUAL((askr::span<int, 2>::extent), 2);
}

BOOST_AUTO_TEST_CASE(DefaultConstructDynmaic)
{
    askr::span<int> s;
    BOOST_CHECK_EQUAL(s.data(), static_cast<int *>(0));
    BOOST_CHECK_EQUAL(s.size(), 0);
}

BOOST_AUTO_TEST_CASE(ConstructDataSize)
{
    int a[4];
    askr::span<int> s(&a[0], 4);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructFirstLast)
{
    int a[4];
    askr::span<int> s(&a[0], &a[4]);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructArrayDynmaic)
{
    int a[4];
    askr::span<int> s(a);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructArrayStatic)
{
    int a[4];
    askr::span<int, 4> s(a);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructStdArrayDynamic)
{
    std::array<int, 4> a;
    askr::span<int> s(a);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructStdArrayStatic)
{
    std::array<int, 4> a;
    askr::span<int, 4> s(a);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructRange)
{
    range<int> c;
    askr::span<int> s(c);
    BOOST_CHECK_EQUAL(s.data(), c.data());
    BOOST_CHECK_EQUAL(s.size(), c.size());
}

BOOST_AUTO_TEST_CASE(ConstructSpanDynamic)
{
    int a[4];
    askr::span<int> s1(askr::span<int>{&a[0], 4});
    BOOST_CHECK_EQUAL(s1.data(), &a[0]);
    BOOST_CHECK_EQUAL(s1.size(), 4);
}

BOOST_AUTO_TEST_CASE(ConstructSpanStatic)
{
    int a[4];
    askr::span<int, 4> s1(askr::span<int, 4>{&a[0], 4});
    BOOST_CHECK_EQUAL(s1.data(), &a[0]);
    BOOST_CHECK_EQUAL(s1.size(), 4);
}

BOOST_AUTO_TEST_CASE(CopyDynamic)
{
    int a[4];
    askr::span<int> s1(&a[0], 4);
    askr::span<int> s2(s1);
    BOOST_CHECK_EQUAL(s2.data(), &a[0]);
    BOOST_CHECK_EQUAL(s2.size(), 4);
}

BOOST_AUTO_TEST_CASE(CopyStatic)
{
    int a[4];
    askr::span<int, 4> s1(&a[0], 4);
    askr::span<int, 4> s2(s1);
    BOOST_CHECK_EQUAL(s2.data(), &a[0]);
    BOOST_CHECK_EQUAL(s2.size(), 4);
}

BOOST_AUTO_TEST_CASE(AssignDynamic)
{
    askr::span<int> s;
    int a[4];
    s = askr::span<int>(&a[0], 4);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 4);
}

BOOST_AUTO_TEST_CASE(AssignStatic)
{
    int a1[4];
    askr::span<int, 4> s1(&a1[0], 4);
    int a2[4];
    s1 = askr::span<int, 4>(&a2[0], 4);
    BOOST_CHECK_EQUAL(s1.data(), &a2[0]);
    BOOST_CHECK_EQUAL(s1.size(), 4);
}

BOOST_AUTO_TEST_CASE(TestFirst)
{
    int a[4];
    askr::span<int, 2> s = askr::span<int>(&a[0], 4).first<2>();
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(TestLast)
{
    int a[4];
    askr::span<int, 2> s = askr::span<int>(&a[0], 4).last<2>();
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(SubSpanDynamic)
{
    int a[4];
    askr::span<int> s = askr::span<int>(&a[0], 4).subspan(2);
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(SubSpanStatic)
{
    int a[4];
    askr::span<int, 4> s1(&a[0], 4);
    askr::span<int, 2> s2 = s1.subspan<2>();
    BOOST_CHECK_EQUAL(s2.data(), &a[2]);
    BOOST_CHECK_EQUAL(s2.size(), 2);
}

BOOST_AUTO_TEST_CASE(SubSpan)
{
    int a[4];
    askr::span<int, 1> s = askr::span<int>(&a[0], 4).subspan<2, 1>();
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 1);
}

BOOST_AUTO_TEST_CASE(TestFirstSize)
{
    int a[4];
    askr::span<int> s = askr::span<int>(&a[0], 4).first(2);
    BOOST_CHECK_EQUAL(s.data(), &a[0]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(TestLastSize)
{
    int a[4];
    askr::span<int> s = askr::span<int>(&a[0], 4).last(2);
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(SubSpanRange)
{
    int a[4];
    askr::span<int> s = askr::span<int>(&a[0], 4).last(2);
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 2);
}

BOOST_AUTO_TEST_CASE(SubSpanRangeCount)
{
    int a[4];
    askr::span<int> s = askr::span<int>(&a[0], 4).subspan(2, 1);
    BOOST_CHECK_EQUAL(s.data(), &a[2]);
    BOOST_CHECK_EQUAL(s.size(), 1);
}

BOOST_AUTO_TEST_CASE(TestEmpty)
{
    int a[4];
    {
        BOOST_TEST(askr::span<int>().empty());
        BOOST_TEST(!askr::span<int>(&a[0], 4).empty());
    }
    {
        BOOST_TEST((askr::span<int, 0>().empty()));
        BOOST_TEST((!askr::span<int, 4>(&a[0], 4).empty()));
    }
}

BOOST_AUTO_TEST_CASE(TestFrontBack)
{
    int a[4] = {1, 2, 3, 4};
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4)[2], 3);
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4).front(), 1);
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4).back(), 4);
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4).data(), &a[0]);
}

BOOST_AUTO_TEST_CASE(TestIterator)
{
    int a[4];
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4).begin(), &a[0]);
    BOOST_CHECK_EQUAL(askr::span<int>(&a[0], 4).end(), &a[4]);
    BOOST_CHECK_EQUAL((askr::span<int>(&a[0], 4).rbegin().base()), &a[4]);
    BOOST_CHECK_EQUAL((askr::span<int>(&a[0], 4).rend().base()), &a[0]);
    BOOST_CHECK_EQUAL((std::begin(askr::span<int>(&a[0], 4))), &a[0]);
    BOOST_CHECK_EQUAL((std::end(askr::span<int>(&a[0], 4))), &a[4]);
}

BOOST_AUTO_TEST_SUITE_END()