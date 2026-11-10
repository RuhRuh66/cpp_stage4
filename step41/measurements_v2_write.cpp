#include <iostream>
#include <fstream>
#include <cstdint>
#include <array>

int main() {
    const char magic[4] = {'M', 'E', 'A', 'S'};
    std::uint32_t type = 1;
    std::uint32_t count = 3;
    std::array<std::int32_t, 3> values{10, 20, 30};

    std::ofstream file("measurements_v2.bin", std::ios::binary);

    if (!file) {
        std::cerr << "cannot open file" << '\n';
        return 1;
    }

    file.write(reinterpret_cast<const char*>(&magic), sizeof(magic));
    file.write(reinterpret_cast<const char*>(&type), sizeof(type));
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    file.write(reinterpret_cast<const char*>(values.data()), sizeof(values));

    if (!file) {
        std::cerr << "write failed\n";
        return 1;
    }

}   