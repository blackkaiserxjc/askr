#pragma once

#include <functional>
#include <tuple>
#include <type_traits>

namespace akr {

template <typename T>
struct function_traits_impl;

template <typename T>
struct function_traits : function_traits_impl<std::remove_cvref_t<T>>
{
};

template <typename Ret, typename... Args>
struct function_traits_impl<Ret(Args...)>
{
    using function_type = std::function<Ret(Args...)>;
    using return_type = Ret;
    using args_type_t = std::tuple<Args...>;
    static constexpr std::size_t arity = sizeof...(Args);

    template <std::size_t I>
    struct args
    {
        static_assert(I < arity, "Index out of range, index must be less than size of args");
        using type = typename std::tuple_element<I, args_type_t>::type;
    };
};
} // namespace akr