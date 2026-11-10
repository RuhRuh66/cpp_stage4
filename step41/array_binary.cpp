#include <array>
#include <fstream>
#include <iostream>

int main() {
    {
    std::array<int, 3> values{10, 20, 30};

    std::ofstream file("array.bin", std::ios::binary);
    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;
    }

    file.write(reinterpret_cast<const char*>(&values), sizeof(values));
    
    if (!file) {
        std::cerr << "write failed\n";
        return 1;
    }
    std::cout << "saved\n";

    }

    std::array<int, 3> restored{};

    {
        std::ifstream file("array.bin", std::ios::binary);
        if (!file) {
            std::cout << "cannot open file\n";
            return 1;
        }
        file.read(reinterpret_cast<char*>(restored.data()), sizeof(restored));

        if (!file) {
            std::cerr << "read failed\n";
            return 1;
        }
    }

    for (int value: restored){
        std::cout << value << '\n';
    }
}

