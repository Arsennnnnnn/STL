#include <iostream>
#include "MyVector.h"

int main() {
    Vector<int> v1{10, 20, 30};
    Vector<int> v2 = std::move(v1);
    v2.printVector();

    return 0;
}