#include <functional>
#include <iostream>
#include "my_shared_ptr.h"

int main() {
    my_shared_ptr<int> ptr(new int(10));
    my_shared_ptr<int> ptr2 = std::move(ptr);
    my_shared_ptr<int> ptr3 = ptr2;
    std::cout << ptr.refCount() << std::endl;
    return 0;
}