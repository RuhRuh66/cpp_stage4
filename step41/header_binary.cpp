#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>

int main() {
    std::array<std::uint32_t, 3> values{10, 20, 30};
    std::uint32_t count = values.size();

    std::ofstream file("measurements.bin", std::ios::binary);
    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;
    }

    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    file.write(reinterpret_cast<const char*>(values.data()), sizeof(values));

    if (!file) {
        std::cerr << "write failed\n";
        return 1;
    }
    std::cout << "header saved\n";

    return 0;
}