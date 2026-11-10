#include <iostream>
#include <string>

int main() {
    std::string a = "\u304c";
    std::string b = "\u304b\u3099";

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';

    std::cout << "a.size(): " << a.size() << '\n';
    std::cout << "b.size(): " << b.size() << '\n';

    std::cout << "a == b: " << (a == b) << '\n';
}
