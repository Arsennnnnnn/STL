#include <iostream>
#include <vector>
#include "my_for_each.h"

struct Sum {
    int value;

    void operator() (int a) {
        value += a;
    }
};


int main() {
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    Sum s = my_for_each(vec.begin(), vec.end(), Sum());
    std::cout << s.value << std::endl;
    return 0;
}