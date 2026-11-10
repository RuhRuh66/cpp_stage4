#include <iostream>
#include <fstream>

int main() {
    int number = 12345;

    std::ofstream file("number.bin", std::ios::binary);
    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;
    }

    file.write(reinterpret_cast<const char*>(&number), sizeof(number));

    if (!file) {
        std::cout << "write failed\n";
        return 1;
    }

    std::cout << "file saved\n";

    return 0;

}