#include "Matrix.h"
#include <iostream>


void matrixMultiplicationNaive(const Matrix<double>& A,
                               const Matrix<double>& B,
                               Matrix<double>& C)
{
    // C(m, n) = A(m, k) * B(k, n)

    auto m = A.row();
    auto K = A.col();
    auto n = B.col();

    // Ensure matrices are compatible for multiplication
    if (A.col() != B.row()) return;

    // Compute each entry of C row by row
    for (int i = 0; i < m; ++i) {
        // Iterate over each column of B / C
        for (int j = 0; j < n; ++j) {

            // Initialize output entry before accumulation
            C(i, j) = 0;

            // Dot product of row i of A and column j of B
            for (int k = 0; k < K; ++k) {
                C(i, j) += A(i, k) * B(k, j);
            }
        }
    }
}

int main()
{
    Matrix<double> A(3, 3);
    A(0, 0) = 5.0;
    std::cout << A(0, 0) << '\n';
    return 0;
}