#include "Matrix.h"
#include <iostream>
#include <chrono>

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
void fillMatrix(Matrix<double>& m, double value)
{
    auto N = m.row();
    auto K = m.col();

    for(int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            m(i,j) = value;
        }
    }
}

double FlopsPerSec(const Matrix<double>& A,
                   const Matrix<double>& B,
                   Matrix<double>& C)
{
    auto m = A.row();
    auto k = A.col();
    auto n = B.col();

    // Record start time
    auto start = std::chrono::high_resolution_clock::now();
    // Call naive implementation
    matrixMultiplicationNaive(A,B,C);
    // Record end time
    auto end = std::chrono::high_resolution_clock::now();
    // Calculate the seconds end - start
    double seconds = std::chrono::duration<double>(end - start).count();

    // Calculate number of flops
    double flops = 2 * m * k * n;

    return flops/seconds/ 1e9;
}

int main()
{
    // Create three 512x512 matrices
    Matrix<double> A(512, 512);
    Matrix<double> B(512, 512);
    Matrix<double> C(512, 512);
    // Fil A and B with 1.0
    fillMatrix(A,1.0);
    fillMatrix(B,1.0);
    // FlopsperSec
    std::cout << FlopsPerSec(A,B,C) << '\n';
    return 0;
}