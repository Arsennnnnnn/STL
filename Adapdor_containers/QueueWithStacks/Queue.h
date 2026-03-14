#ifndef QUEUE_H
#define QUEUE_H
#include <stack>


template <typename T>
class Queue {
private:
    std::stack<T> stack1_;
    std::stack<T> stack2_;
    void transfer() {
        while (!stack1_.empty()) {
            stack2_.push(std::move(stack1_.top()));
            stack1_.pop();
        }
    }
public:
    Queue() {}
    ~Queue() {}

    void push(T item) {
        stack1_.push(std::move(item));
    }

    T pop() {
        if (stack1_.empty() && stack2_.empty()) {
            throw std::runtime_error("Popping from empty queue");
        }
        if (stack2_.empty()) {
            transfer();
        }
        T item = std::move(stack2_.top());
        stack2_.pop();
        return item;
    }

    const T& front() {
        if (stack2_.empty()) {
            transfer();
        }
        return stack2_.top();
    }

};

#endif //QUEUE_H
