#include <iostream>
#include <memory>


int main() {

    int* ptr = nullptr;
    std::weak_ptr<int> ptr2;

    std::cout << "outside block\n";
    std::cout << "ptr: " << ptr << '\n';

    {
        std::shared_ptr<int> owner = std::make_shared<int>(10);
        ptr = owner.get();
        ptr2 = owner;

        std::cout << "inside block\n";
        std::cout << "ptr: " << ptr << '\n';
        std::cout << "*ptr: " << *ptr << '\n';

        std::shared_ptr<int> temp = ptr2.lock();

        if (temp) {
            std::cout << "ptr2: " << *temp << '\n';
        }

    }

    std::cout << "outside block\n";
    std::cout << "ptr: " << ptr << '\n';

    std::shared_ptr<int> temp = ptr2.lock();

    if (temp) {
        std::cout << "ptr2: " << *temp << '\n';
    } else {
        std::cout << "ptr2: object already destroyed\n";
    }

    return 0;
}

