#ifndef __BENCHMARKS_H
#define __BENCHMARKS_H

#include <cstddef>
#include <stack>

template <typename T>
using std_stack = std::stack<T> ;

template <template<typename> typename TStack>
struct stack_simple
{
    static void benchmark(TStack<int>& stack);
};

template <template<typename> typename TStack>
struct stack_complex
{
    static void benchmark(TStack<int>& stack);  
};

template <template<typename> typename TStack>
struct stack_random
{
    static void benchmark(TStack<int>& stack);
};

#include "benchmarks.tpp"

#endif