#include <iostream>
#include <vector>

class Record{
public:
    int value;
    explicit Record(int v) : value(v){}

    Record(const Record& other) : value(other.value) {
        std::cout << "copy: " << value << '\n';
    }

    Record(Record&& other) noexcept : value(other.value) {
        std::cout << "move: " << value << '\n';
    }

};

struct Spirometry {
    double fev;
    double fvc;
};

struct SpirometryData {
    std::vector<double> fev;
    std::vector<double> fvc;
};

int main() {
    SpirometryData patients{{1.8, 2.5, 1.2}, {3.0, 3.5, 2.9}};

    for (std::size_t i = 0; i < patients.fev.size(); ++i) {
        std::cout << "fev: " << patients.fev[i] << " fvc: " << patients.fvc[i] << '\n';
    }



    // std::vector<Record> records;

    // records.reserve(3);

    // records.emplace_back(10);
    // records.emplace_back(20);
    // records.emplace_back(30);
    // std::cout << "size: " << records.size() << '\n';
    // std::cout << "capacity: " << records.capacity() << '\n';

}

