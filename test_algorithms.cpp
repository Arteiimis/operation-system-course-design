#include <sstream>
#include "test_algorithms.hpp"

void test_bankers_algorithm_4(bankers_algorithm& ba) {
    ba = bankers_algorithm(3, 2);
    test_unit_4 test4;
    Vector      resource   = test4.resource;
    Vector      available  = test4.available;
    Matrix      max_demand = test4.max_demand;
    Matrix      allocated  = test4.allocated;
    Matrix      need       = test4.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_1(bankers_algorithm& ba) {
    ba = bankers_algorithm(5, 3);
    test_unit_1 test;
    // Test initialization
    Vector resource   = test.resource;
    Vector available  = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated  = test.allocated;
    Matrix need       = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_2(bankers_algorithm& ba) {
    ba = bankers_algorithm(5, 3);
    test_unit_2 test;
    // Test initialization
    Vector resource   = test.resource;
    Vector available  = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated  = test.allocated;
    Matrix need       = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

void test_bankers_algorithm_3(bankers_algorithm& ba) {
    ba = bankers_algorithm(5, 3);
    test_unit_3 test;
    // Test initialization
    Vector resource   = test.resource;
    Vector available  = test.available;
    Matrix max_demand = test.max_demand;
    Matrix allocated  = test.allocated;
    Matrix need       = test.need;

    ba.init(resource, available, max_demand, allocated, need);
    ba.resource_allocation();
}

std::vector<int> read_vector(int column) {
    std::vector<int> vector;
    while ( true ) {
        std::cin.ignore(100, '\n');
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        int               tmp;
        while ( ss >> tmp ) {
            vector.push_back(tmp);
        }
        if ( vector.size() == column ) {
            break;
        }
        std::cout << "输入向量维度错误，请重新输入：";
        vector.clear();
    }
    return vector;
}

std::vector<std::vector<int>> read_matrix(int row, int column) {
    std::vector<std::vector<int>> matrix;
    std::vector<int>              row_vec;
    std::cout << "按行输入矩阵，大小为 " << row << " 行 " << column << " 列：" << std::endl;
    for ( int i = 0; i < row; i++ ) {
        while ( true ) {
            std::string input;
            std::cout << "第 " << i << " 行：";
            std::getline(std::cin, input);
            std::stringstream ss(input);
            int               tmp;
            while ( ss >> tmp ) {
                row_vec.push_back(tmp);
            }
            if ( row_vec.size() == column ) {
                break;
            }
            std::cout << "输入向量维度错误，请重新输入：" << std::endl;
            row_vec.clear();
        }
        matrix.push_back(row_vec);
        row_vec.clear();
    }
    return matrix;
}


bankers_algorithm input_custem_test_matrix() {
    int    max_processes;
    int    max_resource_types;
    Vector resource;     // 系统总资源数量
    Vector available;    // 系统当前可用资源
    Matrix max_demand;   // 进程最大需求矩阵
    Matrix allocated;    // 已分配资源矩阵
    Matrix need;         // 进程当前需求矩阵

    std::cout << "请输入系统总资源个数：";
    std::cin >> max_resource_types;
    std::cout << "请输入系统进程队列大小：";
    std::cin >> max_processes;
    bankers_algorithm ba = bankers_algorithm(max_processes, max_resource_types);
    std::cout << "请输入系统资源总量：";
    available = resource = Vector(read_vector(max_resource_types));
    std::cout << "请输入最大需求矩阵：";
    max_demand = Matrix(read_matrix(max_processes, max_resource_types));
    std::cout << "请输入已分配资源矩阵：";
    allocated = Matrix(read_matrix(max_processes, max_resource_types));
    need      = max_demand - allocated;

    for ( auto i : allocated.get_matrix() ) {
        available = available - i;
    }

    ba.init(resource, available, max_demand, allocated, need);

    return ba;
}