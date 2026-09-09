#include <iostream>

class CsvReader {
public:
    void read() {
        std::cout << "open csv\n";
    }
};


class DataProcessor {
public:
    void process() {
        reader_.read();
        std::cout << "Data processed\n";
    }
private:
    CsvReader reader_;
};

int main() {
    DataProcessor processor;
    processor.process();

    return 0;
}
