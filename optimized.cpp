#include <iostream>
#include <iomanip>
#include <chrono>

// Function to perform calculations
double calculate(int iterations, int param1, int param2) {
    double result = 1.0;
    for (int i = 1; i <= iterations; ++i) {
        double j1 = static_cast<double>(i) * param1 - param2;
        result -= (1.0 / j1);
        double j2 = static_cast<double>(i) * param1 + param2;
        result += (1.0 / j2);
    }
    return result;
}

int main() {
    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    // Perform the calculation
    double result = calculate(100000000, 4, 1) * 4;

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    
    // Print the results
    std::cout << "Result: " << std::fixed << std::setprecision(12) << result << "\n";
    std::cout << "Execution Time: " << std::fixed << std::setprecision(6) 
              << elapsed.count() << " seconds\n";

    return 0;
}
