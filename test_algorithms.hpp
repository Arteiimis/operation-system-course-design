#ifndef _TEST_ALGORITHMS_CPP_
#define _TEST_ALGORITHMS_CPP_

#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include "algorithms.hpp"

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

void test_bankers_algorithm_4(bankers_algorithm& ba);
void test_bankers_algorithm_1(bankers_algorithm& ba);
void test_bankers_algorithm_2(bankers_algorithm& ba);
void test_bankers_algorithm_3(bankers_algorithm& ba);
std::vector<int> read_vector(int column);
std::vector<std::vector<int>> read_matrix(int row, int column);
bankers_algorithm input_custem_test_matrix();

#endif