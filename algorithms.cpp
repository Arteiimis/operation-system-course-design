#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "algorithms.hpp"
#include "consts.hpp"

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

bool request_resources(int pid, Vector& request, Matrix& allocated, Matrix& maxdemand, Vector& available)
{
    
}