#include <iostream>

int main() {
    int* data = new int[3]{10, 20, 30};

    std::cout << data[3] << '\n';

    delete[] data;

    return 0;
}