#include <cstddef>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <vector>
#include <cstddef>

int main() {
    std::ifstream file("measurements_v2.bin", std::ios::binary);

    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;

    }

    char magic[4]{};

    file.read(magic, sizeof(magic));

    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;

    }

    if (memcmp(magic, "MEAS", 4) != 0) {
        std::cerr << "Invalid file format\n";
        return 1;
    }
    for (char c: magic) {
        std::cout << c;
    }

    std::cout << '\n';
    
    
    std::uint32_t type{};

    file.read(reinterpret_cast<char*>(&type), sizeof(type));
    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;

    }

    if (type != 1) {
        std::cerr << "unsupported data type\n";
        return 1;
    }


    std::cout << "type: " << type << '\n';

    std::uint32_t count{};

    file.read(reinterpret_cast<char*>(&count), sizeof(count));
    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;

    }

    constexpr std::uint32_t Max_count = 1000;
    if (count > Max_count) {
        std::cerr << "too many measurements\n";
        return 1;
    }




    std::cout << "count: " << count << '\n';

    std::vector<std::int32_t> measurements(count);

    std::cout << "vector size: " << measurements.size() << '\n';

    file.read(reinterpret_cast<char*>(measurements.data()), sizeof(int32_t)*measurements.size());

    for (std::int32_t value: measurements){
        std::cout << value << ' ';
    }

    std::cout << '\n';

    std::byte b{0x41};
    std::cout << "byte: " << std::to_integer<int>(b) << '\n';


}