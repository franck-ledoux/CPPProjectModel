#include <iostream>
#include <toy/a/A.h>
#include <toy/b/B.h>
int main() {
    std::cout << "Hello, World!" << std::endl;
    A a;
    a.f(3);
    B b;
    b.g(2);
    return 0;
}
