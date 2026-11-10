#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>


int count;
std::mutex m;

void worker() {
    for (int i = 0; i < 1000000; ++i){
        std::lock_guard<std::mutex> lock(m);
        ++count;
    }
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << count << '\n';
}

