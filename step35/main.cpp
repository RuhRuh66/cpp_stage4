#include <iostream>

[[nodiscard]]
bool check_value(int value) {
    return value >= 0;
}


int main() {
    check_value(-1);

    return 0;
}