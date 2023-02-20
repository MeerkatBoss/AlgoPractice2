#include "benchmarks.h"

#include <type_traits>
#include <stack>
#include <ctime>
#include <random>

#include "array_stack.h"
#include "list_stack.h"

template <template<typename> typename TStack>
void stack_simple<TStack>::benchmark(TStack<int>& stack)
{
    static constexpr size_t start_size = (int)1e6;
    static constexpr size_t end_size   = (int)1e5;

    for (size_t i = 0; i < start_size; i++)
        stack.push(1); 

    while (stack.size() >= end_size)
    {
        size_t size = stack.size();
        for (size_t i = 0; i < size / 2; i++)
            stack.pop();
        for (size_t i = 0; i < size / 4; i++)
            stack.push(1);
    }
    return;
}

template <template<typename> typename TStack>
void stack_complex<TStack>::benchmark(TStack<int>& stack)
{
    static constexpr size_t start_size = (size_t)1e6;
    static constexpr size_t end_size   = (size_t)1e5;
    static constexpr size_t iterations =         100;
    static constexpr size_t added_count= (size_t)1e4;

    for (size_t i = 0; i < start_size; i++)
        stack.push(1); 

    for (size_t i = 0; i < iterations; i++)
    {
        for (size_t j = 0; j < added_count; j++)
            stack.push(1);
        for (size_t j = 0; j < added_count; j++)
            stack.pop();
    }

    while (stack.size() >= end_size)
    {
        size_t size = stack.size();
        for (size_t i = 0; i < size / 2; i++)
            stack.pop();
        for (size_t i = 0; i < size / 4; i++)
            stack.push(1);
    }

    for (size_t i = 0; i < iterations; i++)
    {
        for (size_t j = 0; j < added_count; j++)
            stack.push(1);
        for (size_t j = 0; j < added_count; j++)
            stack.pop();
    }
    
    return;
}

template <template<typename> typename TStack>
void stack_random<TStack>::benchmark(TStack<int>& stack)
{
    static std::random_device entropy = std::random_device();
    static std::default_random_engine engine(entropy());
    static std::uniform_int_distribution<> distribution(1, 2);

    static constexpr size_t start_size = (size_t)1e6;
    static constexpr size_t iterations = (size_t)1e6;

    for (size_t i = 0; i < start_size; i++)
        stack.push(distribution(engine));
    
    for (size_t i = 0; i < iterations; i++)
        switch (stack.top())
        {
        case 1:
            stack.push(distribution(engine));
            break;
        case 2:
            stack.pop();
            break;
        default:
            printf("\nUnexpected value: %d\nStack size: %zu\n",stack.top(), stack.size());
            abort();
            break;
        }
    
    return;
}