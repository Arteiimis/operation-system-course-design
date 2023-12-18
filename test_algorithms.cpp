#include <iostream>
#include <vector>
#include <string>
#include "data_structures.hpp"
#include "algorithms.cpp"

int main()
{
    // Test Case 1: Safe state
    Matrix allocated = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    Matrix maxdemand = { {10, 10, 10}, {10, 10, 10}, {10, 10, 10} };
    Vector available = { 10, 10, 10 };
    std::vector<std::string> safe_sequence = safe_check(allocated, maxdemand, available);
    std::cout << "Safe sequence: ";
    for (const auto& process : safe_sequence) {
        std::cout << process << " ";
    }
    std::cout << std::endl;
    // Output: Safe sequence: Process 0 Process 1 Process 2

    // Test Case 2: Unsafe state
    allocated = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    maxdemand = { {10, 10, 10}, {10, 10, 10}, {10, 10, 10} };
    available = { 0, 0, 0 };
    safe_sequence = safe_check(allocated, maxdemand, available);
    std::cout << "Safe sequence: ";
    for (const auto& process : safe_sequence) {
        std::cout << process << " ";
    }
    std::cout << std::endl;
    // Output: Safe sequence: Unsafe state

    return 0;
}