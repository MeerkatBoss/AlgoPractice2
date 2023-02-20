#ifndef __PROFILERS_H
#define __PROFILERS_H

#include <cstddef>
#include <ctime>

template <template<template<typename> typename> typename TTest,
            template<typename> typename TClass>
inline size_t run_benchmark()
{
    static constexpr size_t try_count = 50;
    size_t sum = 0;
    for (size_t i = 0; i < try_count; i++)
    {
        TClass<int> instance = TClass<int>();
        clock_t clock_start = std::clock();
        TTest<TClass>::benchmark(instance);
        clock_t clock_end = std::clock();
        sum += (size_t)(clock_end - clock_start) / (CLOCKS_PER_SEC / 1000);
    }

    return sum / try_count;
}

template <template<template<typename> typename> typename TTest,
            template<typename> typename... TClasses>
inline void print_results_row(size_t number)
{
    printf("%8zu", number);
    (printf("|%10zums", run_benchmark<TTest, TClasses>()),...);
    putc('\n', stdout);
}

template <template<template<typename> typename> typename... TTests>
struct run_benchmarks
{
    template<template<typename> typename... TClasses>
    static inline void on_classes()
    {
        size_t number = 1;
        (print_results_row<TTests, TClasses...>(number++),...);
    }
};

#endif