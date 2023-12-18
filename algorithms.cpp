#include "algorithms.hpp"
#include <iostream>

/**
 * @brief 检查系统是否处于安全状态，并生成安全序列
 *
 * @param resource  系统资源向量
 * @param available 可用资源向量
 * @param need      进程所需资源矩阵
 * @param allocated 已分配资源矩阵
 * @param n         进程数量
 * @return std::vector<std::string> 安全序列
 */
std::vector<std::string> safe_check(Vector resource, Vector available, Matrix need, Matrix allocated, int n)
{
    std::vector<std::string> safe_sequence; // 安全序列
    Vector work = available;                // 记录当前系统可用资源
    std::vector<bool> finish(n, false);     // 向量工作状态记录
    int count = 0;                          // 记录已完成进程数

    while (count < n) {                 // 当有进程未完成时
        bool flag = false;              // 标记是否有进程可以完成
        for (int i = 0; i < n; ++i) {   // 遍历进程
            // 如果进程未完成且所需资源小于等于可用资源，则完成该需求为安全，将其压入安全序列
            if (!finish[i] && need[i] < work) {
                work = work + allocated[i];     // 更新可用资源
                finish[i] = true;               // 记录进程状态
                safe_sequence.push_back("P" + std::to_string(i));
                flag = true;
                ++count;
            }
        }
        if (!flag) {                    // 如果没有进程可以完成，则说明系统不安全
            safe_sequence.clear();
            break;
        }
    }
    return safe_sequence;
}

void do_resource_allocation(Vector resource, Vector available, Vector request,
                            Matrix max_demand, Matrix allocated, Matrix need)
{
    int id; // 进程id
    std::cout << "进程需求矩阵：" << std::endl;
    need.print();
    std::cout << "当前系统资源总量：" << std::endl;
    resource.print();
    std::cout << "当前系统可用资源矩阵：" << std::endl;
    available.print();
}