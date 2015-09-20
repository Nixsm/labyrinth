#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>

template<typename T> class Matrix {
public:
    Matrix(const unsigned int& rows, const unsigned int& cols);

    void set(const unsigned int& x, const unsigned int& y, const T& value);
    T get(const unsigned int& x, const unsigned int& y) const;


    friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
        for (int i = 0; i < matrix._rows; ++i) {
            for (int j = 0; j < matrix._cols; ++j) {
                os << matrix._data.at(matrix._get2DIdx(i, j));
            }
            os << std::endl;
        }

        return os;
    }

private:
    unsigned int _get2DIdx(const unsigned int& x, const unsigned int& y) const;
    
public:
    std::vector<T> _data;
    unsigned int _rows;
    unsigned int _cols;
};

#endif//MATRIX_H
