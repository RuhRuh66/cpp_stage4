#include <iostream>
#include <cassert>

int add(int a, int b) {
    return a + b;
}

int main() {
    assert(add(2, 3) == 5);

    std::cout << "All tests passed\n";

    return 0;
}