#include <iostream>
#include <string>
#include <vector>
#include "data_structures.hpp"

Vector resource[max_resource_types];                    // 系统资源总量
Vector available[max_resource_types];                   // 系统当前可用资源
Vector request[max_resource_types];                     // 进程请求资源
Matrix max_demand[max_processes];                       // 最大需求矩阵
Matrix allocated[max_processes][max_resource_types];    // 当前分配矩阵
Matrix need[max_processes];                             // 进程需求矩阵
std::vector<std::string> safe_sequence;                 // 安全序列