#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include "my_vector.h"

template<typename T>
class my_queue : private my_vector<T> {
public:
    bool empty() const {
        return my_vector<T>::empty();
    }
    T front() const {
        return my_vector<T>::front();
    }
    T back() const {
        return my_vector<T>::back();
    }
    std::size_t size() const {
        return my_vector<T>::size();
    }
    void push (const T& value) {
        my_vector<T>::push_back(value);
    }
    void pop () {
        if (my_vector<T>::empty()) {
            std::cout << "can not pop, already empty" << std::endl;
        }
        my_vector<T>::erase(0);
    }


};


#endif //MY_QUEUE_H
