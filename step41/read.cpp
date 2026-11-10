#include <fstream>
#include <iostream>


int main() {
    int number = 12345;

    {
        std::ofstream file("number.bin", std::ios::binary);
        if (!file) {
            std::cerr << "cannot open file for writing\n";
            return 1;
        }

        file.write(reinterpret_cast<const char*>(&number), sizeof(number));

        if (!file) {
            std::cerr << "write failed\n";
            return 1;
        }
    }

    int restored = 0;

    {
        std::ifstream file("number.bin", std::ios::binary);

        if (!file) {
            std::cerr << "cannot open file for reading\n";
            return 1;
        }

        file.read(reinterpret_cast<char*>(&restored), sizeof(restored));

        if (!file) {
            std::cerr << "read failed\n";
            return 1;
        }
    }

    std::cout << restored << '\n';

}