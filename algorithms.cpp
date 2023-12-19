#include <iostream>
#include <ostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "data_structures.hpp"

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
    bankers_algorithm(int max_resource_types = 5, int max_processes = 10)
        : max_resource_types(max_resource_types), max_processes(max_processes)
    {
        resource = Vector(max_resource_types);
        available = Vector(max_resource_types);
        max_demand = Matrix(max_processes, max_resource_types);
        allocated = Matrix(max_processes, max_resource_types);
        need = Matrix(max_processes, max_resource_types);
    }

    void init(Vector resource, Vector available, Matrix max_demand,
                Matrix allocated, Matrix need)
    {
        this->resource = resource;
        this->available = available;
        this->max_demand = max_demand;
        this->allocated = allocated;
        this->need = need;
    }

    // 单次资源分配前安全检查
    safe_sequence_t safe_check(Matrix allocated, Matrix maxdemand, Vector available) const
    {
        safe_sequence_t safe_sequence;
        std::vector<bool> finished(allocated.get_size(), false);

        while (true) {
            bool found = false;
            // 遍历所有进程
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
            return safe_sequence_t{ "Unsafe state" };
        }

        return safe_sequence;
    }

    bool resource_allocation()
    {
        int pid = 0;
        curr_sys_info_print();
        while (true) {
            std::cout << "请输入请求资源的进程号，输入2887退出资源申请：";
            std::cin >> pid;
            if (pid == 2887) {
                std::cout << "退出资源申请" << std::endl;
                return true;
            }
            std::cout << "请输入该进程需求向量(request)：";
            std::vector<int> request_vector;
            while (true) {
                std::string input;
                std::cin >> input;
                std::stringstream ss(input);
                int tmp;
                while (ss >> tmp) {
                    request_vector.push_back(tmp);
                }
                if (request_vector.size() == max_resource_types) {
                    break;
                }
                std::cout << "输入的向量维度不正确，请重新输入: ";
                std::cout.sync_with_stdio();
            }

            request = Vector(request_vector);
            std::cout << "请求进程id：" << pid << " 请求向量：";
            request.print();

            if (request > need[pid]) {
                std::cout << "该程序最大需求：";
                need[pid].print();
                std::cout << "请求资源大于进程最大需求，分配失败" << std::endl;
                continue;
            }
            if (request > available) {
                std::cout << "当前系统可用资源：";
                available.print();
                std::cout << "当前系统资源不足，分配失败" << std::endl;
                continue;
            }

            available = available - request;
            allocated[pid] = allocated[pid] + request;
            need[pid] = need[pid] - request;

            safe_sequence = safe_check(allocated, max_demand, available);
            if (safe_sequence.size() != max_processes) {
                std::cout << "未找到安全序列，该测试序列不安全，执行回滚操作" << std::endl;
                available = available + request;
                allocated[pid] = allocated[pid] - request;
                need[pid] = need[pid] + request;
                continue;
            }
            else {
                std::cout << "找到安全序列，该测试序列安全，安全序列如下：" << std::endl;
                std::cout << " ";
                for (auto i : safe_sequence) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
                check_if_task_complate();
                std::cout << "确认分配操作：" << std::endl;
                curr_sys_info_print();
                continue;
            }
        }
    }

    void check_if_task_complate()
    {
        for (int i = 0; i < max_processes; ++i) {
            if (need[i] == Vector(3, 0)) {
                std::cout << "第i个进程已经满足最大需求，回收其占有的资源" << std::endl;
                available = available + allocated[i];
                allocated[i] = Vector(3, 0);
            }
        }
    }

    void curr_sys_info_print() const
    {
        std::cout << "当前系统信息:" << std::endl;
        std::cout << "系统当前可用资源数：";
        available.print();
        std::cout << "最大需求数:" << "\t" << "已分配数据:" << "\t" << "最多还需要:" << std::endl;
        for (int i = 0; i < allocated.get_size(); ++i) {
            max_demand[i].print_whitout_newline();
            std::cout << "\t\t";
            allocated[i].print_whitout_newline();
            std::cout << "\t\t";
            need[i].print_whitout_newline();
            std::cout << std::endl;
        }
    }

    void safe_check_test() const
    {
        std::cout << "----安全序列测试----" << std::endl;
        curr_sys_info_print();
        while (true) {
            int pid;
            std::cout << "请输入请求资源的进程号，2887退出：";
            std::cin >> pid;
            if (pid == 2887) {
                std::cout << "退出安全序列测试" << std::endl;
                return;
            }
            std::cout << "请输入该进程需求向量(request)：";
            std::vector<int> request_vector;
            while (true) {
                std::string input;
                std::cin >> input;
                std::stringstream ss(input);
                int tmp;
                while (ss >> tmp) {
                    request_vector.push_back(tmp);
                }
                if (request_vector.size() == max_resource_types) {
                    break;
                }
                std::cout << "输入的向量维度不正确，请重新输入：";
            }
            auto m_request = Vector(request_vector);
            std::cout << "请求进程id：" << pid << " 请求向量：";
            m_request.print();
            auto m_allocated = allocated;
            auto m_need = need;
            auto m_available = available;

            m_available = m_available - m_request;
            m_allocated[pid] = m_allocated[pid] + m_request;
            m_need[pid] = m_need[pid] - m_request;

            auto safe_sequence = safe_check(m_allocated, max_demand, m_available);
            if (safe_sequence.size() != max_processes) {
                std::cout << "未找到安全序列，该测试序列不安全。" << std::endl;
                continue;
            }
            else {
                std::cout << "该次资源分配安全，安全序列如下：" << std::endl;
                for (auto i : safe_sequence) {
                    std::cout << i << std::endl;
                }
                continue;
            }
        }
    }
};