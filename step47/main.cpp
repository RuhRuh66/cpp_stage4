#include <iostream>
#include <chrono>
#include <ratio>

long long calculate_sum(int n){
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cerr << "Usage: ./check <number>\n";
        return 1;
    }

    int n = std::stoi(argv[1]);

    auto start = std::chrono::steady_clock::now();

    long long result = calculate_sum(n);
    
    auto end = std::chrono::steady_clock::now();

    std::chrono::duration<double, std::milli> elapsed = end - start;

    std::cout << "sum: " << result << '\n';
    std::cout << "elapsed: " << elapsed.count() << " ms\n";

    return 0;
}