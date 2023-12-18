#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <algorithm>
#include "algorithms.hpp"

/**
 *@brief 安全检查
 *
 * @param allocated 已分配资源
 * @param maxdemand 最大需求矩阵
 * @param available 系统当前可用资源
 * @return std::vector<std::string>
 */
std::vector<std::string> safe_check(Matrix& allocated, Matrix& maxdemand, Vector& available)
{
    std::vector<std::string> safe_sequence;
    std::vector<bool> finished(allocated.get_size(), false);

    while (true) {
        bool found = false;
        for (size_t i = 0; i < allocated.get_size(); ++i) {
            if (!finished[i] && maxdemand[i] - allocated[i] <= available) {
                safe_sequence.push_back("Process " + std::to_string(i));
                available = available + allocated[i];
                finished[i] = true;
                found = true;
            }
        }
        if (!found) {
            break;
        }
    }

    if (std::find(finished.begin(), finished.end(), false) != finished.end()) {
        return std::vector<std::string>{"Unsafe state"};
    }

    return safe_sequence;
}

/**
 *@brief 资源申请
 *
 * @param pid       进程id
 * @param available 系统当前可用资源
 * @param maxdemand 最大需求矩阵
 * @param allocated 当前分配矩阵
 * @param need      进程当前需求矩阵
 * @return true     申请成功
 * @return false    申请失败
 */
bool request_resources(int pid, Vector& available, Matrix& maxdemand,
                        Matrix& allocated, Matrix& need)
{
    // 当前系统信息打印，自动对齐

    std::cout << "当前系统信息:" << std::endl;
    std::cout << "最大需求数:" << "\t" << "已分配数据:" << "\t" << "最多还需要:" << std::endl;
    for (int i = 0; i < allocated.get_size(); ++i) {
        maxdemand[i].print_whitout_newline();
        std::cout << "\t\t";
        allocated[i].print_whitout_newline();
        std::cout << "\t\t";
        need[i].print_whitout_newline();
        std::cout << std::endl;
    }

    // 检查进程pid的资源请求是否合法
    if (need[pid] <= available) {
        // 模拟分配资源给进程pid
        available = available - need[pid];
        allocated[pid] = allocated[pid] + need[pid];
        need[pid] = Vector(0); // 进程已满足需求，将其需求置为0

        // 检查系统是否处于安全状态
        std::vector<std::string> safe_sequence = safe_check(allocated, maxdemand, available);
        if (safe_sequence.size() == allocated.get_size()) {
            // 输出系统信息
            std::cout << "资源分配成功！" << std::endl;
            std::cout << "当前系统信息:" << std::endl;
            // 输出安全序列
            std::cout << "安全序列:";
            for (auto& process : safe_sequence) {
                std::cout << process << " ";
            }
            std::cout << std::endl;
            std::cout << "最大需求数:" << "\t" << "已分配数据:" << "\t" << "最多还需要:" << std::endl;
            for (int i = 0; i < allocated.get_size(); ++i) {
                maxdemand[i].print_whitout_newline();
                std::cout << "\t\t";
                allocated[i].print_whitout_newline();
                std::cout << "\t\t";
                need[i].print_whitout_newline();
                std::cout << std::endl;
            }
            return true;
        }
        else {
            // 回滚分配的资源
            available = available + need[pid];
            allocated[pid] = allocated[pid] - need[pid];
            need[pid] = maxdemand[pid] - allocated[pid];
            std::cout << "资源分配失败，系统处于不安全状态！" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "资源分配失败，进程需求超过系统可用资源！" << std::endl;
        return false;
    }
}