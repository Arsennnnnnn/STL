#include <iostream>

struct base {
    virtual void f() = 0;
};

struct derived : base {
    derived() { f();}
    void f() { std::cout << "derived" << std::endl; }
};

int main() {
    derived d;
    d.f();
    base& b = static_cast<base&>(d);
    b.f();
    return 0;
}