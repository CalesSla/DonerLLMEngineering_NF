#include <iostream>
#include <iomanip>
#include <chrono>

// Function to calculate the desired result
double calculate(int iterations, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j = static_cast<double>(i * param1 - param2);
        result -= (1.0 / j);
        j = static_cast<double>(i * param1 + param2);
        result += (1.0 / j);
    }
    return result;
}

int main() {
    // Starting timer
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform calculation
    double result = calculate(100000000, 4, 1) * 4;

    // Ending timer
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    // Output results
    std::cout << std::fixed << std::setprecision(12)
              << "Result: " << result << std::endl
              << "Execution Time: " << elapsed.count() << " seconds" << std::endl;

    return 0;
}
