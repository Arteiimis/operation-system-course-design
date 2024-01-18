#ifndef _DATA_STRUCTURES_HPP_INCLUDED
#define _DATA_STRUCTURES_HPP_INCLUDED

#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <vector>

class Vector
{
private:
    std::vector<int> v;

public:
    Vector() = default;
    Vector(int size) { v.resize(size); }
    Vector(const Vector& v) : v(v.v) {}           // 拷贝构造函数
    Vector(Vector&& v) : v(std::move(v.v)) {}     // 移动构造函数
    Vector(const std::vector<int>& v) : v(v) {}   // 从vector构造
    // Vector(int list[], int size) : v(list, list + size) { } // 从数组构造
    Vector(size_t count, int value) : v(count, value) {}   // 从count个value构造
    Vector(std::initializer_list<int> m) {
        for ( auto& i : m ) {
            v.push_back(i);
        }
    }
    ~Vector() = default;

    int&       operator[](int i) { return v[i]; }
    const int& operator[](int i) const { return v[i]; }   // 重载[]运算符
    Vector&    operator=(const Vector& v) {
        this->v = v.v;
        return *this;
    }
    Vector& operator=(Vector&& v) {
        this->v = std::move(v.v);
        return *this;
    }
    bool operator==(const Vector& v) const {
        return (this->v == v.v && this->v.size() == v.v.size());
    }
    Vector operator+(const Vector& v) {
        Vector tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.v.push_back(this->v[i] + v.v[i]);
        }
        return tmp;
    }
    Vector operator-(const Vector& v) {
        Vector tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.v.push_back(this->v[i] - v.v[i]);
        }
        return tmp;
    }
    bool operator>(const Vector& v) {
        // 存在一个大于则返回 ture
        std::vector<bool> tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.push_back(this->v[i] > v.v[i]);
        }
        return std::any_of(tmp.begin(), tmp.end(), [](bool i) { return i; });
    }
    bool operator<(const Vector& v) {
        // 全都小于则返回 ture
        std::vector<bool> tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.push_back(this->v[i] < v.v[i]);
        }
        return std::all_of(tmp.begin(), tmp.end(), [](bool i) { return i; });
    }
    bool operator>=(const Vector& v) {
        // 全都大于等于返回 true
        std::vector<bool> tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.push_back(this->v[i] >= v.v[i]);
        }
        return std::all_of(tmp.begin(), tmp.end(), [](bool i) { return i; });
    }
    bool operator<=(const Vector& v) {
        // 全都小于等于返回 true
        std::vector<bool> tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.push_back(this->v[i] <= v.v[i]);
        }
        return std::all_of(tmp.begin(), tmp.end(), [](bool i) { return i; });
    }
    bool operator!=(const Vector& v) {
        // 一个分量不等于则返回 true
        std::vector<bool> tmp;
        for ( int i = 0; i < this->v.size(); ++i ) {
            tmp.push_back(this->v[i] != v.v[i]);
        }
        return std::any_of(tmp.begin(), tmp.end(), [](bool i) { return i; });
    }
    int              get_size() const { return v.size(); }
    std::vector<int> get_vector() const { return v; }
    void             print() const {
        for ( int i = 0; i < v.size(); ++i ) {
            // 输出自动对齐
            std::cout.width(2);
            std::cout << v[i] << " ";
        }
        std::cout << std::endl;
    }
    void print_whitout_newline() const {
        for ( int i = 0; i < v.size(); ++i ) {
            // 输出自动对齐
            std::cout.width(2);
            std::cout << v[i];
        }
    }
};

class Matrix
{
private:
    std::vector<Vector> m;

public:
    Matrix() = default;
    Matrix(const Matrix& m) : m(m.m) {}              // 拷贝构造函数
    Matrix(Matrix&& m) : m(std::move(m.m)) {}        // 移动构造函数
    Matrix(const std::vector<std::vector<int>>& m)   // 从vector构造
    {
        for ( auto& i : m ) {
            this->m.push_back(Vector(i));
        }
    }
    Matrix(std::initializer_list<std::initializer_list<int>> m) {
        for ( auto& i : m ) {
            this->m.push_back(Vector(i));
        }
    }
    Matrix(int row, int column) {
        for ( int i = 0; i < row; ++i ) {
            m.push_back(Vector(column));
        }
    }
    ~Matrix() = default;

    Vector&       operator[](int i) { return m[i]; }
    const Vector& operator[](int i) const { return m[i]; }   // 重载[]运算符
    Matrix&       operator=(const Matrix& m) {
        this->m = m.m;
        return *this;
    }
    Matrix& operator=(Matrix&& m) {
        this->m = std::move(m.m);
        return *this;
    }
    Matrix operator+(const Matrix& m) {
        Matrix tmp;
        for ( int i = 0; i < this->m.size(); ++i ) {
            tmp.m.push_back(this->m[i] + m.m[i]);
        }
        return tmp;
    }
    Matrix operator-(const Matrix& m) {
        Matrix tmp;
        for ( int i = 0; i < this->m.size(); ++i ) {
            tmp.m.push_back(this->m[i] - m.m[i]);
        }
        return tmp;
    }

    void remove(int i) {
        auto it = m.begin();
        m.erase(it + i);
    }

    int                 get_size() const { return m.size(); }
    Vector              get_row(int i) const { return m[i]; }
    std::vector<Vector> get_matrix() const { return m; }
    void                print() const {
        for ( auto& i : m ) {
            i.print();
        }
    }
};

#endif   // _DATA_STRUCTURES_HPP_INCLUDED