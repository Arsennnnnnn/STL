#include <iostream>
#include "LinkedList.h"


int main() {
    mstd::List<int> intList;

    intList.push_back(10);
    intList.push_back(20);
    intList.push_back(30);
    intList.push_front(5);
    intList.insert(2, 15);
    return 0;
}