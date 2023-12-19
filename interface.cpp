#include <iostream>
#include <ostream>
#include <string>
#include "test_algorithms.cpp"

void display_menu()
{
    std::cout << "┌---------------------------------┐" << std::endl;
    std::cout << "│1. init system data              │" << std::endl;
    std::cout << "│2. view current system info      │" << std::endl;
    std::cout << "│3. safe check test               │" << std::endl;
    std::cout << "│4. run resource allocation test  │" << std::endl;
    std::cout << "│5. view all built-in test        │" << std::endl;
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
            // Test initialization
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
            ba.safe_check_test();
            break;

        }
        case 4:
        {
            std::cout << "即将执行测试单元 1 , 确认? (Y/n):";
            std::string choice;
            std::cin >> choice;
            if (choice == "\t" || choice == "y") {
                test_bankers_algorithm_1(ba);
            }
            else {
                std::cout << "单元测试 1 取消" << std::endl;
            }

            std::cout << "即将执行测试单元 2 , 确认? (Y/n):";
            std::cin >> choice;
            std::cin.sync();
            if (choice == "\t" || choice == "y") {
                test_bankers_algorithm_2(ba);
            }
            else {
                std::cout << "单元测试 2 取消" << std::endl;
            }
            break;

        }
        case 5:
        {
            built_in_test_viewer();
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