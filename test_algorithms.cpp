#include <iostream>
#include "algorithms.cpp"

void test_request_resources()
{
    // Test case 1: Request resources for a valid process
    Vector available1({ 10, 5, 7 });
    Matrix maxdemand1({ {7, 5, 3}, {3, 2, 2}, {9, 0, 2} });
    Matrix allocated1({ {0, 1, 0}, {2, 0, 0}, {3, 0, 2} });
    Matrix need1({ {7, 4, 3}, {1, 2, 2}, {6, 0, 0} });
    int pid1 = 1;
    bool result1 = request_resources(pid1, available1, maxdemand1, allocated1, need1);
    std::cout << "Test case 1: ";
    if (result1) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }

    // Test case 2: Request resources for an invalid process
    Vector available2({ 10, 5, 7 });
    Matrix maxdemand2({ {7, 5, 3}, {3, 2, 2}, {9, 0, 2} });
    Matrix allocated2({ {0, 1, 0}, {2, 0, 0}, {3, 0, 2} });
    Matrix need2({ {7, 4, 3}, {1, 2, 2}, {6, 0, 0} });
    int pid2 = 2;
    bool result2 = request_resources(pid2, available2, maxdemand2, allocated2, need2);
    std::cout << "Test case 2: ";
    if (!result2) {
        std::cout << "Passed" << std::endl;
    }
    else {
        std::cout << "Failed" << std::endl;
    }
}

int main()
{
    test_request_resources();
    return 0;
}