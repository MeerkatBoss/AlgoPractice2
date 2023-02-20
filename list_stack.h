#ifndef __LIST_STACK_H
#define __LIST_STACK_H

#include <cstddef>

template <typename T>
class ListStack
{
private:
    struct ListNode
    {
        T value;
        ListNode* parent;
        ListNode(T val, ListNode* p) : value(val), parent(p) {}
    };

    ListNode* root_;
    size_t size_;
public:

    ListStack(void) : root_(nullptr), size_(0) {}
    ListStack(const ListStack<T>& stack) = delete;
    bool push(const T& value);
    T top() const;
    bool pop(void);
    size_t size(void) const { return size_; }
    ListStack<T>& operator=(const ListStack<T>& stack) = delete;
    ~ListStack();
};

#include "list_stack.tpp"

#endif