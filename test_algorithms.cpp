#include <iostream>
#include <ostream>
#include "algorithms.cpp"

// 大于系统最大可用资源
struct test_unit_3
{
    Vector resource = { 2, 3, 2 };
    Vector available;
    Matrix max_demand = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2},{2, 2, 2}, {4, 3, 3} };
    Matrix allocated = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    Matrix need;
    test_unit_3()
    {
        this->available = resource;
        this->need = max_demand - allocated;
        for (auto i : allocated.get_matrix()) {
            available = available - i;
        }
    }
};

struct test_unit_1
{
    Vector resource = { 10, 5, 7 };
    Vector available;
    Matrix max_demand = { {7, 5, 3}, {3, 2, 2}, {9, 0, 2},{2, 2, 2}, {4, 3, 3} };
    Matrix allocated = { {0, 1, 0}, {2, 0, 0}, {3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    Matrix need;
    test_unit_1()
    {
        this->available = resource;
        this->need = max_demand - allocated;
        for (auto i : allocated.get_matrix()) {
            available = available - i;
        }
    }
};

struct test_unit_2
{
    Vector resource = { 10, 5, 7 };
    Vector available;
    Matrix max_demand = { {8, 5, 3},{3, 2, 2},{9, 5, 2},{2, 2, 2},{4, 3, 6} };
    Matrix allocated = { {0, 1, 0},{2, 0, 0},{3, 0, 2}, {2, 1, 1}, {0, 0, 2} };
    Matrix need;
    test_unit_2()
    {
        this->available = resource;
        this->need = max_demand - allocated;
        for (auto i : allocated.get_matrix()) {
            available = available - i;
        }
    }
};

struct test_unit_4
{
    Vector resource = { 7, 15 };
    Vector available;
    Matrix max_demand = { {6, 5}, {3, 8}, {4, 7} };
    Matrix allocated = { {1, 3},{2, 6},{2, 3} };
    Matrix need;
    test_unit_4()
    {
        this->available = resource;
        this->need = max_demand - allocated;
        for (auto i : allocated.get_matrix()) {
            available = available - i;
        }
    }
};

void test_bankers_algorithm_4(bankers_algorithm& ba)
{
    ba = bankers_algorithm(2, 3);
    test_unit_4 test4;
    Vector resource = test4.resource;
    Vector available = test4.available;
    Matrix max_demand = test4.max_demand;
    Matrix allocated = test4.allocated;
    Matrix need = test4.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_1(bankers_algorithm& ba)
{
    ba = bankers_algorithm(3, 5);
    test_unit_1 test;
    // Test initialization
    Vector resource = test.resource;
    Vector available = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated = test.allocated;
    Matrix need = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_2(bankers_algorithm& ba)
{
    ba = bankers_algorithm(3, 5);
    test_unit_2 test;
    // Test initialization
    Vector resource = test.resource;
    Vector available = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated = test.allocated;
    Matrix need = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_3(bankers_algorithm& ba)
{
    ba = bankers_algorithm(3, 5);
    test_unit_3 test;
    // Test initialization
    Vector resource = test.resource;
    Vector available = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated = test.allocated;
    Matrix need = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void built_in_test_viewer()
{

}

// int main()
// {
//     test_bankers_algorithm_1();
//     return 0;
// }