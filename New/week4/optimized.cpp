
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <climits>

class LCG {
private:
    uint64_t value;
    static constexpr uint64_t a = 1664525ULL;
    static constexpr uint64_t c = 1013904223ULL;
    static constexpr uint64_t m = 4294967296ULL; // 2^32

public:
    LCG(uint64_t seed) : value(seed) {}
    
    uint64_t next() {
        value = (a * value + c) % m;
        return value;
    }
};

long long max_subarray_sum(int n, uint64_t seed, int min_val, int max_val) {
    LCG lcg_gen(seed);
    std::vector<int> random_numbers;
    random_numbers.reserve(n);
    
    int range = max_val - min_val + 1;
    for (int i = 0; i < n; ++i) {
        random_numbers.push_back(static_cast<int>(lcg_gen.next() % range) + min_val);
    }
    
    long long max_sum = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        long long current_sum = 0;
        for (int j = i; j < n; ++j) {
            current_sum += random_numbers[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }
    return max_sum;
}

long long total_max_subarray_sum(int n, uint64_t initial_seed, int min_val, int max_val) {
    long long total_sum = 0;
    LCG lcg_gen(initial_seed);
    
    for (int i = 0; i < 20; ++i) {
        uint64_t seed = lcg_gen.next();
        total_sum += max_subarray_sum(n, seed, min_val, max_val);
    }
    return total_sum;
}

int main() {
    int n = 10000;
    uint64_t initial_seed = 42;
    int min_val = -10;
    int max_val = 10;
    
    auto start_time = std::chrono::high_resolution_clock::now();
    long long result = total_max_subarray_sum(n, initial_seed, min_val, max_val);
    auto end_time = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
    double execution_time = duration.count() / 1000000.0;
    
    std::cout << "Total Maximum Subarray Sum (20 runs): " << result << std::endl;
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) << execution_time << " seconds" << std::endl;
    
    return 0;
}
