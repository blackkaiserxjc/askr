#pragma once

#include <functional>
#include <tuple>
#include <type_traits>

namespace askr {

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

template <size_t I, typename Function>
using arg_type = typename function_traits<Function>::template args<I>::type;

// function pointer
template <typename R, typename... Args>
struct function_traits_impl<R (*)(Args...)> : function_traits<R(Args...)>
{
};

// std::function
template <typename R, typename... Args>
struct function_traits_impl<std::function<R(Args...)>> : function_traits_impl<R(Args...)>
{
};

// member function
template <typename R, typename T, typename... Args>
struct function_traits_impl<R (T::*)(Args...)> : function_traits_impl<R(Args...)>
{
};

template <typename R, typename T, typename... Args>
struct function_traits_impl<R (T::*)(Args...) const> : function_traits_impl<R(Args...)>
{
};

template <typename R, typename T, typename... Args>
struct function_traits_impl<R (T::*)(Args...) volatile> : function_traits_impl<R(Args...)>
{
};

template <typename R, typename T, typename... Args>
struct function_traits_impl<R (T::*)(Args...) const volatile> : function_traits_impl<R(Args...)>
{
};

// functor
template <typename Callable>
struct function_traits_impl : function_traits_impl<decltype(&Callable::operator())>
{
};

template <typename Function>
auto to_function(const Function &lambda)
{
    using function_type = typename function_traits<Function>::function_type;
    return static_cast<function_type>(lambda);
}

template <typename Function>
auto to_function(Function &&lambda)
{
    using function_type = typename function_traits<Function>::function_type;
    return static_cast<function_type>(std::forward<Function>(lambda));
}

} // namespace askr