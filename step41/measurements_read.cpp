#include <iostream>
#include <fstream>
#include <cstdint>
#include <vector>

int main() {
    {
        std::ifstream file("measurements.bin", std::ios::binary);
        
        if (!file) {
            std::cerr << "cannnot open file\n";
            return 1;
        }

        std::uint32_t count{};

        file.read(reinterpret_cast<char*>(&count), sizeof(count));

        constexpr std::uint32_t MAX_COUNT = 1000;
        if (count > MAX_COUNT) {
            std::cerr << "too many measurements: " << count << '\n';
            return 1;
        }

        std::vector<std::uint32_t> values(count);

        file.read(reinterpret_cast<char*>(values.data()), values.size() * sizeof(std::int32_t));



        if (!file) {
            std::cerr << "read failed\n";
            return 1;
        }

        std::cout << "count: " << count << '\n';
        for (std::uint32_t value : values) {
            std::cout << value << '\n';
        }

    }
}