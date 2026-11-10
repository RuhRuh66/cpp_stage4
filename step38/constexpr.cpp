#include <iostream>

class Multiplier {
public:
    Multiplier(int factor) {
        factor_ = factor;
    }

    int operator()(int x) const {
        return factor_ * x;
    }

private:
    int factor_;
};

int main() {
    Multiplier m{3};
    Multiplier n{4};

    std::cout << m(8) << '\n';
    std::cout << n(8) << '\n';

    return 0;

}