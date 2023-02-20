#include "array_stack.h"

#include <algorithm>
#include <cstring>

template <typename T>
ArrayStack<T>::ArrayStack(void) : size_(0), capacity_(stack_default_capacity_), data_(nullptr)
{
    data_ = new T[stack_default_capacity_];
    std::fill(data_, data_+stack_default_capacity_, T());
}

template <typename T>
bool ArrayStack<T>::push(const T& value)
{
    if (!ensure_can_push()) return false;
    data_[size_++] = value;
    return true;
}

template <typename T>
T ArrayStack<T>::top() const
{
    if (!size_) return T();
    return data_[size_-1];
}

template <typename T>
bool ArrayStack<T>::pop(void)
{
    if (!size_) return false;
    data_[--size_] = T();
    return true;
}

template <typename T>
ArrayStack<T>::~ArrayStack()
{
    delete[] data_;
}

template <typename T>
bool ArrayStack<T>::ensure_can_push()
{
    if (size_ < capacity_) return true;

    T *new_data = new T[stack_growth_*capacity_];
    if (!new_data) return false;

    std::memmove(new_data, data_, capacity_ * sizeof(*data_));
    std::fill(new_data + capacity_, new_data + capacity_*stack_growth_, T());

    delete[] data_;
    data_ = new_data;
    capacity_ *= stack_growth_;
    return true;
}
