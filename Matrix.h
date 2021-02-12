//
// Created by nomapunk on 12.02.2021.
//

#ifndef LINAL_MATRIX_H
#define LINAL_MATRIX_H

#include "Rational.h"
#include <iostream>
#include <vector>
#include <assert.h>
#include <algorithm>

template <typename T>
class Matrix {
public:
    std::vector<std::vector<T>> a;
    Matrix() {

    }
    Matrix(std::vector<std::vector<T>> x) {
        a = x;
    }
    Matrix(int m, int n) {
        a.resize(m, std::vector<T>(n));
    }
    std::vector<T> operator[](int i) const {
        return a[i];
    }
    std::vector<T>& operator[](int i) {
        return a[i];
    }
    int M() const {
        return a.size();
    }
    int N() const {
        return a[0].size();
    }
    bool operator==(const Matrix &other) const {
        if (other.N() != this->N()) {
            return false;
        }
        if (other.M() != this->M()) {
            return false;
        }
        for (int i = 0; i < other.M(); i++) {
            for (int j = 0; j < other.N(); j++) {
                if (a[i][j] != other[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    Matrix operator+(const Matrix &other) const {
        assert(this->M() == other.M());
        assert(this->N() == other.N());
        Matrix res(a);
        for (int i = 0; i < res.M(); i++) {
            for (int j = 0; j < res.N(); j++) {
                res[i][j] += other[i][j];
            }
        }
        return res;
    }
    Matrix operator-(const Matrix &other) const {
        assert(this->M() == other.M());
        assert(this->N() == other.N());
        Matrix res(a);
        for (int i = 0; i < res.M(); i++) {
            for (int j = 0; j < res.N(); j++) {
                res[i][j] -= other[i][j];
            }
        }
        return res;
    }
    Matrix operator*(const Matrix &other) const {
        assert(this->N() == other.M());
        Matrix res(this->M(), other.N());
        for (int i = 0; i < res.M(); i++) {
            for (int j = 0; j < res.N(); j++) {
                for (int k = 0; k < other.M(); k++) {
                    res.a[i][j] += a[i][k] * other[k][j];
                }
            }
        }
        return res;
    }
    Matrix operator^(int power) const {
        Matrix res = a;
        for (int i = 1; i < power; i++) {
            res = res * *this;
        }
        return res;
    }
    Matrix operator*(const T scalar) const {
        Matrix res = a;
        for (int i = 0; i < res.M(); i++) {
            for (int j = 0; j < res.N(); j++) {
                res[i][j] = res[i][j] * scalar;
            }
        }
        return res;
    }
    Matrix operator|(const Matrix &other) const {
        assert(this->M() == other.M());
        Matrix res = a;
        for (int i = 0; i < this->M(); i++) {
            for (auto x : other.a[i]) {
                res[i].push_back(x);
            }
        }
        return res;
    }
    Matrix operator~() const {
        Matrix res(this->N(), this->M());
        for (int i = 0; i < this->M(); i++) {
            for (int j = 0; j < this->N(); j++) {
                res[j][i] = a[i][j];
            }
        }
        return res;
    }
};

template <typename T>
std::ostream& operator <<(std::ostream &out, Matrix<T> a) {
    for (int i = 0; i < a.M(); i++) {
        for (int j = 0; j < a.N(); j++) {
            out << a[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

template <typename T>
Matrix<T> get_f1(int m, int n, int i, int j, T X) {
    Matrix<T> res(m, n);
    for (int it = 0; it < m; it++) {
        res[it][it] = 1;
    }
    res[i][j] = X;
    return res;
};

template <typename T>
Matrix<T> get_f2(int m, int n, int i, int j, T kek) {
    Matrix<T> res(m, n);
    for (int it = 0; it < m; it++) {
        res[it][it] = 1;
    }
    res[i][i] = res[j][j] = 0;
    res[j][i] = res[i][j] = 1;
    return res;
};

template <typename T>
Matrix<T> get_f3(int m, int n, int i, T X) {
    Matrix<T> res(m, n);
    for (int it = 0; it < m; it++) {
        res[it][it] = 1;
    }
    res[i][i] = X;
    return res;
};

template <typename T>
void Gaus(Matrix<T> a, bool show = false) {
    int j = 0;
    std::vector<bool> bad(a.N());
    if (show) std::cout << a << std::endl;
    std::vector<std::pair<int, int>> main_ind;
    for (int i = 0; i < a.M(); i++) {
        bool ok = false;
        if (j >= a.N()) {
            break;
        }
        for (int k = i; k < a.M(); k++) {
            if (a[k][j] != T(0)) {
                std::swap(a[i], a[k]);
                if (show) std::cout << "f2(" << i << ", " << k << ")=>\n";
                if (show) std::cout << a << std::endl;
                ok = true;
                break;
            }
        }
        if (ok) {
            main_ind.push_back({i, j});
            T del = a[i][j];
            if (show) std::cout << "f3(" << i << ", " << (1 / del) << ")=>\n";
            for (int z = j; z < a.N(); z++) {
                a[i][z] /= del;
            }
            if (show) std::cout << a << std::endl;
            for (int k = i + 1; k < a.M(); k++) {
                T x = a[k][j] / a[i][j];
                if (show) std::cout << "f1(" << k << ", " << i << ", " << -x << ")=>\n";
                for (int z = j; z < a.N(); z++) {
                    a[k][z] = a[k][z] - x * a[i][z];
                }
                if (show) std::cout << a << std::endl;
            }
        }
        j++;
        if (!ok) {
            i--;
        }
    }
    if (show) {
        std::cout << "forward\n" << a << std::endl;
    }
    while (main_ind.size()) {
        int i = main_ind.back().first;
        j = main_ind.back().second;
        main_ind.pop_back();
        for (int k = i - 1; k >= 0; k--) {
            T x = a[k][j] / a[i][j];
            if (show) std::cout << "f1(" << k << ", " << i << ", " << -x << ")=>\n";
            for (int z = j; z < a.N(); z++) {
                a[k][z] = a[k][z] - x * a[i][z];
            }
            if (show) std::cout << a << std::endl;
        }
    }
    if (show) {
        std::cout << "back\n" << a << std::endl;
    }
}

template <typename T>
Matrix<T> QGaus(Matrix<T> a, bool show = false) {
    assert(a.M() == a.N());
    Matrix<T> res(a.N(), a.N());
    for (int it = 0; it < a.N(); it++) {
        res[it][it] = 1;
    }
    int j = 0;
    std::vector<bool> bad(a.N());
    if (show) std::cout << a << std::endl;
    std::vector<std::pair<int, int>> main_ind;
    for (int i = 0; i < a.M(); i++) {
        bool ok = false;
        if (j >= a.N()) {
            break;
        }
        for (int k = i; k < a.M(); k++) {
            if (a[k][j] != T(0)) {
                std::swap(a[i], a[k]);
                if (show) std::cout << "f2(" << i << ", " << k << ")=>\n";
                if (show) std::cout << a << std::endl;
                res = get_f2(a.N(), a.N(), i, k, a[i][j]) * res;
                ok = true;
                break;
            }
        }
        if (ok) {
            main_ind.push_back({i, j});
            T del = a[i][j];
            if (show) std::cout << "f3(" << i << ", " << (1 / del) << ")=>\n";
            res = get_f3(a.N(), a.N(), i, 1 / del) * res;
            for (int z = j; z < a.N(); z++) {
                a[i][z] /= del;
            }
            if (show) std::cout << a << std::endl;
            for (int k = i + 1; k < a.M(); k++) {
                T x = a[k][j] / a[i][j];
                if (show) std::cout << "f1(" << k << ", " << i << ", " << -x << ")=>\n";
                res = get_f1(a.N(), a.N(), k, i, -x) * res;
                for (int z = j; z < a.N(); z++) {
                    a[k][z] = a[k][z] - x * a[i][z];
                }
                if (show) std::cout << a << std::endl;
            }
        }
        j++;
        if (!ok) {
            i--;
        }
    }
    if (show) {
        std::cout << "forward\n" << a << std::endl;
    }
    while (main_ind.size()) {
        int i = main_ind.back().first;
        j = main_ind.back().second;
        main_ind.pop_back();
        for (int k = i - 1; k >= 0; k--) {
            T x = a[k][j] / a[i][j];
            if (show) std::cout << "f1(" << k << ", " << i << ", " << -x << ")=>\n";
            res = get_f1(a.N(), a.N(), k, i, -x) * res;
            for (int z = j; z < a.N(); z++) {
                a[k][z] = a[k][z] - x * a[i][z];
            }
            if (show) std::cout << a << std::endl;
        }
    }
    if (show) {
        std::cout << "back\n" << a << std::endl;
    }
    return res;
}

template <typename T>
bool check(Matrix<T> a, std::vector<T> vals) {
    for (int i = 0; i < a.M(); i++) {
        T res = 0;
        for (int j = 0; j < a.N() - 1; j++) {
            res += a[i][j] * vals[j];
        }
        if (res != a[i].back()) {
            return false;
        }
    }
    return true;
}

template <typename T>
T tr(Matrix<T> a) {
    T res = 0;
    for (int i = 0; i < a.M(); i++) {
        res += a[i][i];
    }
    return res;
}

#endif //LINAL_MATRIX_H
