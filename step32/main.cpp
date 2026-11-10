#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <utility>


struct Result {
    std::string name;
    double value;
};

class Analysis {
public:
    virtual Result analyze(const std::vector<double>& data) const = 0;
    virtual ~Analysis() = default;
};

class AverageAnalysis : public Analysis {
public:
    Result analyze(const std::vector<double>& data) const override {
        double sum = 0.0;

        for (double value : data) {
            sum += value;
        }

        return {"Average", sum/data.size()};

    }
};

class AnalysisProcessor {
public:
    explicit AnalysisProcessor(std::unique_ptr<Analysis> analysis) : analysis_(std::move(analysis)) {}

    Result run(const std::vector<double>& data) const {
        return analysis_->analyze(data);
    }
        
private:
    std::unique_ptr<Analysis> analysis_;
};

int main() {
    std::vector<double> data{10.0, 20.0, 30.0};

    auto av = std::make_unique<AverageAnalysis>();

    AnalysisProcessor process(std::move(av));

    Result ans = process.run(data);

    std::cout << ans.name << " : " << ans.value << '\n';

    return 0;

}