#include "Matrix.h"

int main() {
    Matrix<Rational> A = std::vector<std::vector<Rational>>{
            {-5, 3,  7},
            {4,  -6, -7}
    };
    Matrix<Rational> B = std::vector<std::vector<Rational>>{
            {-2, -6, -5},
            {1,  4,  1}
    };
    Matrix<Rational> C = std::vector<std::vector<Rational>>{
            {7, -2},
            {5, -2}
    };
    Matrix<Rational> D = std::vector<std::vector<Rational>>{
            {2, 7},
            {7, -1}
    };
    Matrix<Rational> ans =
            D * 6 * B * ~B
            + (B + A) * tr(~A * A) * (~B - ~A)
            + (C ^ 2) * 4
            + (C * 8) * D
            + (D ^ 2) * 4;
    std::cout << ans;
}