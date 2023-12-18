#include <iostream>
#include "data_structures.hpp"

int main()
{
    // Test Case 1: Default constructor
    Matrix m1;
    m1.print();  // Output: 

    // Test Case 2: Copy constructor
    Matrix m2 = m1;
    m2.print();  // Output: 

    // Test Case 3: Move constructor
    Matrix m3 = std::move(m2);
    m3.print();  // Output: 

    // Test Case 4: Construct from vector
    std::vector<std::vector<int>> vec = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    Matrix m4(vec);
    m4.print();
    // Output: 1 2 3
    //         4 5 6
    //         7 8 9

    // Test Case 5: Construct from initializer list
    Matrix m5 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    m5.print();
    // Output: 1 2 3
    //         4 5 6
    //         7 8 9

    // Test Case 6: Access elements using operator[]
    int element = m5[1][2];
    std::cout << "Element at index [1][2]: " << element << std::endl;  // Output: Element at index [1][2]: 6

    // Test Case 7: Assignment operator
    Matrix m6;
    m6 = m5;
    m6.print();
    // Output: 1 2 3
    //         4 5 6
    //         7 8 9

    // Test Case 8: Addition operator
    Matrix m7 = m5 + m6;
    m7.print();
    // Output: 2 4 6
    //         8 10 12
    //         14 16 18

    // Test Case 9: Subtraction operator
    Matrix m8 = m7 - m6;
    m8.print();
    // Output: 1 2 3
    //         4 5 6
    //         7 8 9

    // Test Case 10: Get matrix as vector
    std::vector<std::vector<int>> matrix = m8.get_matrix();
    std::cout << "Matrix as vector: " << std::endl;
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}