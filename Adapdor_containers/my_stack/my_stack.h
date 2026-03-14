#ifndef MY_STACK_H
#define MY_STACK_H

#include "my_vector.h"

template <typename T>
class my_stack : private my_vector<T> {
public:
    bool empty() const {
        return my_vector<T>::empty();
    }
    std::size_t size() const {
        return my_vector<T>::size();
    }
    T top() const {
        return my_vector<T>::back();
    }
    void pop() {
        my_vector<T>::pop_back();
    }
    void push(const T value) {
        my_vector<T>::push_back(value);
    }

};


#endif //MY_STACK_H
