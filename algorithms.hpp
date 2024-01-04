#ifndef _ALGORITHMS_HPP_
#define _ALGORITHMS_HPP_

#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include "data_structures.hpp"
#include "cross_platform.hpp"

class bankers_algorithm
{
public:
    using safe_sequence_t = std::vector<std::string>;
private:
    int max_resource_types;   // 最大资源种类数
    int max_processes;       // 最大进程数

    Vector resource;
    Vector available;
    Vector request;
    Matrix max_demand;
    Matrix allocated;
    Matrix need;
    std::vector<std::string> safe_sequence;

public:
    bankers_algorithm() = default;
    bankers_algorithm(int max_processes = 10, int max_resource_types = 5)
        : max_resource_types(max_resource_types), max_processes(max_processes)
    {
        resource = Vector(max_resource_types);
        available = Vector(max_resource_types);
        max_demand = Matrix(max_processes, max_resource_types);
        allocated = Matrix(max_processes, max_resource_types);
        need = Matrix(max_processes, max_resource_types);
    }

    void init(Vector resource, Vector available, Matrix max_demand, Matrix allocated, Matrix need);
    // 单次资源分配前安全检查
    safe_sequence_t safe_check(Matrix allocated, Matrix maxdemand, Vector available) const;

    void curr_system_safe_check();
    bool resource_allocation();
    void check_if_task_complate();
    void curr_sys_info_print() const;
    void safe_check_test() const;
};

#endif