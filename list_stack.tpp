#include "list_stack.h"

template <typename T>
bool ListStack<T>::push(const T& value)
{
    ListNode* new_node = new ListNode(value, root_);
    if (!new_node) return false;
    root_ = new_node;
    size_++;
    return true;
}

template <typename T>
T ListStack<T>::top() const
{
    if (!root_) return T();
    return root_->value;
}

template <typename T>
bool ListStack<T>::pop(void)
{
    if (!root_) return false;
    ListNode* top = root_;
    root_ = root_->parent;
    size_--;
    delete top;
    return true;
}

template <typename T>
ListStack<T>::~ListStack()
{
    while (root_)
    {
        ListNode* top = root_;
        root_ = root_->parent;
        delete top;
    }
}
