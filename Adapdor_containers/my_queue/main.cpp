#include <iostream>
#include "my_queue.h"
int main() {
    my_queue<int> my_queue;
    my_queue.push(12);
    my_queue.push(13);
    my_queue.push(14);
    my_queue.push(15);
    my_queue.push(16);
    my_queue.push(17);

    std::cout << my_queue.front() << std::endl;
    my_queue.pop();
    std::cout << my_queue.front() << std::endl;
    my_queue.pop();
    std::cout << my_queue.front() << std::endl;
    my_queue.pop();
    std::cout << my_queue.front() << std::endl;
    my_queue.pop();
    return 0;
}