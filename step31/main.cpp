#include <iostream>

int main() {
    int x = 10;
    int& ref = x;

    auto a = ref;
    decltype(ref) b = x;

    a = 20;
    b = 30;

    std::cout << "x: " << x << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    return 0;
}