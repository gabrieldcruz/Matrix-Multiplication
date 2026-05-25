// Header guard to precent a header from being included more than once
#pragma once
#include <vector>


// Function-like definition
template <typename T>

class Matrix
{
 private:
    std::vector <T> matrix;
    int rows;
    int cols;

 public:
    Matrix(int r, int c)
    {
        rows = r;
        cols = c;
        matrix.resize(rows * cols);
    }

    int row() const
    {
        return rows;
    }

    int col() const
    {
        return cols;
    }

    // for reading (const objects)
    const T& operator()(int i, int j) const
    {
        int index = i * cols + j;
        return matrix[index];
    }

    // for writing (non-const objects)
    T& operator()(int i, int j)
    {
    int index = i * cols + j;
    return matrix[index];
    }
};

