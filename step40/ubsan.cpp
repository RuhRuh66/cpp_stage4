#include <iostream>
#include <limits>

int main() {
    int max_value = std::numeric_limits<int>::max();
    int result = max_value + 1;

    std::cout << result << '\n';

    return 0;
}