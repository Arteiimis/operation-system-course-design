#ifndef _ALGORITHMS_HPP_INCLUDED
#define _ALGORITHMS_HPP_INCLUDED

#include "data_structures.hpp"
#include <string>
#include <vector>

// 安全检查
std::vector<std::string> safe_check(Matrix& allocated, Matrix& maxdemand, Vector& available);
// 资源获取
void resource_allocation(Vector resource, Vector available, Vector request,
                            Matrix max_demand, Matrix allocated, Matrix need);

#endif // _ALGORITHMS_HPP_INCLUDED