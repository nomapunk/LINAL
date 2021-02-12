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

    // ~A = A транспонированая

    Matrix<Rational> C1 = std::vector<std::vector<Rational>>{
            {1, 3},
            {4, 2}
    };

    Matrix<Rational> C2 = QGaus(C1);
    // Находит обратну матрицу (просто находит на какую матрицу нужно умножить, чтобы УСП
    // Получить

    std::cout << C1 << std::endl;

    std::cout << C2 << std::endl;

    std::cout << C1 * C2 << std::endl;

    // еще можно через черточку матрицы записывать, что-бы красиво решать уравнения.

    std::cout << (C1 | C2);

    //Gaus(C1, 1);
    //Запустит гаусса и покажет какие элементарные преобразования делал и что получил.
    //Можно пускать без флага show.
}