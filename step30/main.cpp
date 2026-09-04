#include <iostream>
#include <memory>

class DataSource {
public:
    virtual void open() = 0;

    virtual ~DataSource() = default;
};

class CsvDataSource final : public DataSource {
public:
    void open() final {
        std::cout << "open csv\n";
    }

~CsvDataSource() = default;

};

class SpecialDataSource : public CsvDataSource {
public:
    void open() override {
        std::cout << "open special csv\n";
    }

};



int main() {
    std::unique_ptr<DataSource> source = std::make_unique<CsvDataSource>();
    source->open();


    return 0;
 
}