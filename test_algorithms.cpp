#include <iostream>
#include <ostream>
#include "algorithms.cpp"

void test_bankers_algorithm()
{
    bankers_algorithm ba = bankers_algorithm(3, 5);

    // Test initialization
    Vector resource = { 10, 5, 7 };
    Vector available = resource;
    Vector request = { 1, 0, 2 };
    Matrix max_demand = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2},{2, 2, 2}, {4, 3, 3} };
    Matrix allocated = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    Matrix need = max_demand - allocated;
    for (auto i : allocated.get_matrix()) {
        available = available - i;
    }

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

int main()
{
    test_bankers_algorithm();
    return 0;
}