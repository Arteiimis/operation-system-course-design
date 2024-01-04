#include <iostream>
#include <ostream>
#include <string>
#include "test_algorithms.hpp"
#include "algorithms.hpp"

void display_menu()
{
    std::cout << "┌---------------------------------┐" << std::endl;
    std::cout << "│1. init system data              │" << std::endl;
    std::cout << "│2. view current system info      │" << std::endl;
    std::cout << "│3. safe check test               │" << std::endl;
    std::cout << "│4. run resource allocation test  │" << std::endl;
    std::cout << "│5. input custem test matrix      │" << std::endl;
    std::cout << "│                                 │" << std::endl;
    std::cout << "│6. exit                          │" << std::endl;
    std::cout << "└---------------------------------┘" << std::endl;
}

void interface()
{
    bankers_algorithm ba = bankers_algorithm(3, 5);
    while (true) {
        system("cls");
        display_menu();
        std::cout << "请输入选项：";
        int option;
        std::cin >> option;
        system("cls");
        switch (option) {
        case 1:
        {
            std::cout << "即将使用测试数据 1 初始化系统资源..." << std::endl;
            test_unit_1 test;
            // 测试数据初始化
            Vector resource = test.resource;
            Vector available = test.available;
            Matrix max_demand = test.max_demand;
            Matrix allocated = test.allocated;
            Matrix need = test.need;
            ba.init(resource, available, max_demand, allocated, need);
            std::cout << "系统资源初始化完毕" << std::endl;
            system("pause");
            break;
        }
        case 2:
        {
            ba.curr_sys_info_print();
            system("pause");
            break;

        }
        case 3:
        {
            ba.curr_system_safe_check();
            system("pause");
            break;
        }
        case 4:
        {
            std::cout << "请选择测试单元：" << std::endl;
            std::cout << "1. 测试单元 1" << std::endl;
            std::cout << "2. 测试单元 2" << std::endl;
            std::cout << "3. 测试单元 3" << std::endl;
            std::cout << "请输入选项：";
            int option;
            std::string choice;
            std::cin >> option;
            switch (option) {
            case 1:
                goto test_1;
            case 2:
                goto test_2;
            case 3:
                goto test_3;
            case 4:
                break;
            default:
            {
                std::cout << "无效选项" << std::endl;
                break;
            }
            }
            break;
        test_1:
            std::cout << "即将执行测试单元 1 , 确认? (Y/n):";
            std::cin >> choice;
            if (choice == "\t" || choice == "y") {
                system("cls");
                test_bankers_algorithm_1(ba);
            }
            else {
                std::cout << "单元测试 1 取消" << std::endl;
            }
            break;

        test_2:
            std::cout << "即将执行测试单元 2 , 确认? (Y/n):";
            std::cin >> choice;
            if (choice == "\t" || choice == "y") {
                system("cls");
                test_bankers_algorithm_2(ba);
            }
            else {
                std::cout << "单元测试 2 取消" << std::endl;
            }
            break;
        test_3:
            std::cout << "即将执行测试单元 3 , 确认? (Y/n):";
            std::cin >> choice;
            if (choice == "\t" || choice == "y") {
                system("cls");
                test_bankers_algorithm_3(ba);
            }
            else {
                std::cout << "单元测试 3 取消" << std::endl;
            }
        }
        case 5:
        {
            while (true) {
                ba = input_custem_test_matrix();
                std::cout << "自定义测试矩阵如下：" << std::endl;
                ba.curr_sys_info_print();
                std::cout << "确认测试数据？(Y/n):";
                // std::cin.ignore(INT_MAX, '\n');
                std::string choice;
                std::getline(std::cin, choice);
                if (choice != "n") {
                    break;
                }
                std::cout << "请重新输入：" << std::endl;
            }
            ba.resource_allocation();
            break;
        }
        case 6:
        {
            return;
        }
        }
    }
}

int main()
{
    interface();
    return 0;
}