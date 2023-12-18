#ifndef _ALGORITHMS_HPP_INCLUDED
#define _ALGORITHMS_HPP_INCLUDED

#include "data_structures.hpp"
#include <string>
#include <vector>

std::vector<std::string> safe_check(Vector resource, Vector available,
                                    Matrix need, Matrix allocated, int n);
void do_resource_allocation(Vector resource, Vector available, Vector request,
                            Matrix max_demand, Matrix allocated, Matrix need);

#endif // _ALGORITHMS_HPP_INCLUDED