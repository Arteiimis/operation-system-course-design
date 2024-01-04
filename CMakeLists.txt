cmake_minimum_required(VERSION 3.15)
project(BankersAlgorithm)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(. DIR_SRCS)
add_executable(BankersAlgorithm ${DIR_SRCS})