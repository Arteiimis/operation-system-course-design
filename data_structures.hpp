#ifndef _DATA_STRUCTURES_HPP_INCLUDED
#define _DATA_STRUCTURES_HPP_INCLUDED

#include <vector>
#include <iostream>

#include "consts.hpp"

class Vector
{
private:
    std::vector<int> v;
public:
    Vector() = default;
    Vector(const Vector& v) : v(v.v) { }                    // 拷贝构造函数
    Vector(Vector&& v) : v(std::move(v.v)) { }              // 移动构造函数
    Vector(const std::vector<int>& v) : v(v) { }            // 从vector构造
    Vector(int list[], int size) : v(list, list + size) { } // 从数组构造
    ~Vector() = default;

    int& operator[](int i) { return v[i]; }
    const int& operator[](int i) const { return v[i]; }     // 重载[]运算符
    Vector& operator=(const Vector& v) { this->v = v.v; return *this; }
    Vector& operator=(Vector&& v) { this->v = std::move(v.v); return *this; }
    Vector operator+(const Vector& v)
    {
        Vector tmp;
        for (int i = 0; i < this->v.size(); ++i) {
            tmp.v.push_back(this->v[i] + v.v[i]);
        }
        return tmp;
    }
    Vector operator-(const Vector& v)
    {
        Vector tmp;
        for (int i = 0; i < this->v.size(); ++i) {
            tmp.v.push_back(this->v[i] - v.v[i]);
        }
        return tmp;
    }
    bool operator>(const Vector& v)
    {
        for (int i = 0; i < this->v.size(); ++i) {
            if (this->v[i] <= v.v[i]) {
                return false;
            }
        }
        return true;
    }
    bool operator<(const Vector& v)
    {
        for (int i = 0; i < this->v.size(); ++i) {
            if (this->v[i] >= v.v[i]) {
                return false;
            }
        }
        return true;
    }
    int get_size() const { return v.size(); }
    std::vector<int> get_vector() const { return v; }
    void print() const
    {
        for (int i = 0; i < v.size(); ++i) {
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
};

class Matrix
{
private:
    std::vector<Vector> m;

public:
    Matrix() = default;
    Matrix(Matrix&& m) : m(std::move(m.m)) { }               // 移动构造函数
    Matrix(const Matrix& m) : m(m.m) { }                     // 拷贝构造函数
    Matrix(const std::vector<Vector>& m) : m(m) { }          // 从Vector构造
    Matrix(const std::vector<std::vector<int>>& m)           // 从二维std::vector构造
    {
        for (int i = 0; i < m.size(); ++i) {
            this->m.push_back(Vector(m[i]));
        }
    }
    Matrix(int list[][max_resource_types], int size)          // 从二维数组构造
    {
        for (int i = 0; i < size; ++i) {
            this->m.push_back(Vector(list[i], max_resource_types));
        }
    }
    ~Matrix() = default;

    Vector& operator[](int i) { return m[i]; }
    const Vector& operator[](int i) const { return m[i]; }   // 重载[]运算符
    Matrix operator-(const Matrix& m)
    {
        Matrix tmp;
        for (int i = 0; i < this->m.size(); ++i) {
            tmp.m.push_back(this->m[i] - m.m[i]);
        }
        return tmp;
    }
    Matrix operator+(const Matrix& m)
    {
        Matrix tmp;
        for (int i = 0; i < this->m.size(); ++i) {
            tmp.m.push_back(this->m[i] + m.m[i]);
        }
        return tmp;
    }
    void print() const
    {
        for (int i = 0; i < m.size(); ++i) {
            m[i].print();
        }
    }
};

#endif // _DATA_STRUCTURES_HPP_INCLUDED