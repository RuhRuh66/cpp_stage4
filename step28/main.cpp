#include <iostream>


class Measurement {
public:
    Measurement(double value): value_(value) {
        std::cout << "constructed: " << value_ << '\n';
    }

    ~Measurement() {
        std::cout << "destroyed: " << value_ << '\n';
    }

private:
    double value_;

};

int main() {
    std::cout << "main start\n";

    {
        Measurement fev1(2.85);
        std::cout << "inside block\n";
    }

    std::cout << "outside block\n";

    return 0;

}