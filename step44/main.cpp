#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

    
int levenshtein(const std::string& a, const std::string& b){
    int n = static_cast<int>(a.size());
    int m = static_cast<int>(b.size());

    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1, 0));

    for (int i = 0; i < n + 1; ++i) {
        dp[i][0] = static_cast<int>(i);
    }

    for (int j = 0; j < m + 1; ++j){
        dp[0][j] = static_cast<int>(j);
    }
    
    
    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < m + 1; ++j) {
            int cost = (a[i - 1] == b[j - 1]) ? 0 : 1;
            dp[i][j]  = std::min({
                dp[i][j-1] + 1,
                dp[i-1][j] + 1,
                dp[i-1][j-1] + cost}
            );
        }
    }

    return dp[n][m];

}
int main() {
    std::vector<std::pair<std::string, std::string>> records {
        {"FEV1", "一秒量"},
        {"FEV1/FVC", "1秒率"},
        {"FVC", "努力肺活量"},
        {"DLCO", "拡散能"},
        {"TLC", "全肺気量"},
        {"FENO", "呼気一酸化炭素濃度"}
    };

    std::unordered_map<std::string, std::string> index;

    for (const auto& [name, description] : records) {
        index.emplace(name, description);
    }

    std::cout << "indexed: " << index.size() << " records\n";

    std::string input;

    while(true) {
        std::cout << "\nSearch(quit to exit): ";
        std::getline(std::cin, input);

        if (!std::cin || input == "quit") break;

        auto it = index.find(input);

        if (it != index.end()){
            std::cout << "Exact match: " << it->first << " - " << it->second <<'\n';
        } else {
            bool found = false;

            for (const auto& [code, description] : index) {
                if (code.starts_with(input)){
                    std::cout << code << " - " << description << '\n';
                    found = true;
                }
            }
            if (!found) {
                std::string best_code;
                int best_distance = std::numeric_limits<int>::max();

                for (const auto& [code, description] : index) {
                    int result = levenshtein(code, input);
                    if (result <= best_distance) {
                        best_distance = result;
                        best_code = code;
                    }
                }
                if (best_distance <= 1) {
                    std::cout << "Did you mean " << best_code << "?\n";
                } else {
                    std::cout << "no suitable match\n";
                }

            }

        }

    }
    std::cout << "Goodbye!\n";

}