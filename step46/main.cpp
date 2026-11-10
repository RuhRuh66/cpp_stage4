#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <future>


std::map<std::string, int> count_data(const std::vector<std::string>& list, int begin, int end){
    std::map<std::string, int> count;

    for (int i = begin; i < end; ++i) {
        std::string normalized = list[i];
        std::transform(normalized.begin(), normalized.end(),
         normalized.begin(), [](unsigned char c){return static_cast<char>(std::toupper(c));});
    
         ++count[normalized];
    }

    return count;
}

int main() {
    std::vector<std::string> data;

    std::ifstream file("data.txt");

    if (!file) {
        std::cerr << "cannot open file\n";
        return 1;
    }

    std::string line;

    while (std::getline(file, line)){
        data.push_back(line);
    }

    std::cout << "loaded " << data.size() << " records\n";

    int middle = static_cast<int>(data.size() /2);
    int end = static_cast<int>(data.size());

    auto f1 = std::async(std::launch::async, count_data, std::cref(data), 0, middle);
    auto f2 = std::async(std::launch::async, count_data, std::cref(data), middle, end);

    auto count1 = f1.get();
    auto count2 = f2.get();

    for (const auto& [name, count] : count2) {
        count1[name] += count;
    }

    for (const auto& [name, count] : count1) {
        std::cout << name << ": " << count <<  '\n';
    }




    return 0;
}

