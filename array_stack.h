#ifndef __ARRAY_STACK_H
#define __ARRAY_STACK_H

#include <cstddef>


template <typename T>
class ArrayStack
{
private:
    static constexpr size_t stack_default_capacity_ = 16;
    static constexpr size_t stack_growth_ = 2;

    bool ensure_can_push(void);

    size_t size_;
    size_t capacity_;
    T *data_;

public:
    ArrayStack(void);
    ArrayStack(const ArrayStack<T>& array) = delete;
    bool push(const T& value);
    T top() const;
    bool pop(void);
    size_t size(void) const { return size_; }
    ArrayStack<T>& operator=(const ArrayStack<T>& stack) = delete;
    ~ArrayStack();
};

#include "array_stack.tpp"

#endif