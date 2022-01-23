#include <boost/test/unit_test.hpp>

#include <askr/meta/function_traits.h>
#include <askr/meta/type_traits.h>

#include <functional>
#include <string>

BOOST_AUTO_TEST_SUITE(FunctionTraits)

int foo(int, float, bool, std::string)
{
    return 42;
}

class Object
{
public:
    int foo(int, float, bool, std::string)
    {
        return 42;
    }

    int operator()(int, float, bool, std::string)
    {
        return 42;
    }
};

BOOST_AUTO_TEST_CASE(BasicTestCase)
{
    // function type
    {
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::return_type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::args_type_t, std::tuple<int, float, bool, std::string>>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<0>::type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<1>::type, float>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<2>::type, bool>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<3>::type, std::string>);
        static_assert(std::is_same_v<askr::arg_type<0, decltype(foo)>, int>);
        static_assert(std::is_same_v<askr::arg_type<1, decltype(foo)>, float>);
        static_assert(std::is_same_v<askr::arg_type<2, decltype(foo)>, bool>);
        static_assert(askr::function_traits<decltype(foo)>::arity == 4);
    }
    // std::function
    {
        std::function<int(int, float, bool, std::string)> foo = [](int, float, bool, std::string) -> int { return 42; };
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::return_type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<0>::type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<1>::type, float>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<2>::type, bool>);
        static_assert(std::is_same_v<askr::arg_type<0, decltype(foo)>, int>);
        static_assert(std::is_same_v<askr::arg_type<1, decltype(foo)>, float>);
        static_assert(std::is_same_v<askr::arg_type<2, decltype(foo)>, bool>);
        static_assert(askr::function_traits<decltype(foo)>::arity == 4);
    }

    // member function
    {
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::return_type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::args_type_t, std::tuple<int, float, bool, std::string>>);
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::template args<0>::type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::template args<1>::type, float>);
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::template args<2>::type, bool>);
        static_assert(std::is_same_v<askr::function_traits<decltype(&Object::foo)>::template args<3>::type, std::string>);
        static_assert(std::is_same_v<askr::arg_type<0, decltype(&Object::foo)>, int>);
        static_assert(std::is_same_v<askr::arg_type<1, decltype(&Object::foo)>, float>);
        static_assert(std::is_same_v<askr::arg_type<2, decltype(&Object::foo)>, bool>);
        static_assert(askr::function_traits<decltype(&Object::foo)>::arity == 4);
    }

    // functor
    {
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::return_type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::args_type_t, std::tuple<int, float, bool, std::string>>);
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::template args<0>::type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::template args<1>::type, float>);
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::template args<2>::type, bool>);
        static_assert(std::is_same_v<askr::function_traits<decltype(Object())>::template args<3>::type, std::string>);
        static_assert(std::is_same_v<askr::arg_type<0, decltype(Object())>, int>);
        static_assert(std::is_same_v<askr::arg_type<1, decltype(Object())>, float>);
        static_assert(std::is_same_v<askr::arg_type<2, decltype(Object())>, bool>);
        static_assert(askr::function_traits<decltype(Object())>::arity == 4);
    }

    // lambda
    {
        auto foo = [](int, float, bool, std::string) -> int { return 42; };
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::return_type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<0>::type, int>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<1>::type, float>);
        static_assert(std::is_same_v<askr::function_traits<decltype(foo)>::template args<2>::type, bool>);
        static_assert(std::is_same_v<askr::arg_type<0, decltype(foo)>, int>);
        static_assert(std::is_same_v<askr::arg_type<1, decltype(foo)>, float>);
        static_assert(std::is_same_v<askr::arg_type<2, decltype(foo)>, bool>);
        static_assert(askr::function_traits<decltype(foo)>::arity == 4);
    }
}

BOOST_AUTO_TEST_SUITE_END()