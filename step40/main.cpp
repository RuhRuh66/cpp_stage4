#include <iostream>

int add(int a, int b) {
    int result = a + b;
    return result;
}

int main() {
    int x = 10;
    int y = 20;

    int answer = add(x, y);

    std::cout << "answer: " << answer << '\n';

    return 0;
}