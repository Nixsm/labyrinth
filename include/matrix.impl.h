#ifndef MATRIX_IMPL_H
#define MATRIX_IMPL_H

#include "matrix.h"

template<typename T> Matrix<T>::Matrix(const unsigned int& rows, const unsigned int& cols)
    :_rows(rows), _cols(cols), _data(std::vector<T>(rows * cols))
{

}

template<typename T> T Matrix<T>::get( const unsigned int &x, const unsigned int &y ) const {
    return _data.at(_get2DIdx(x, y));
}

template<typename T> void Matrix<T>::set( const unsigned int &x, const unsigned int &y, const T &value ) {
    _data.at(_get2DIdx(x, y)) = value;
}


template<typename T> T Matrix<T>::get(const Point<unsigned int>& point) const {
    return _data.at(_get2DIdx(point.getX(), point.getY()));
}

template<typename T> void Matrix<T>::set(const Point<unsigned int>& point, const T &value ) {
    _data.at(_get2DIdx(point.getX(), point.getY())) = value;
}

template<typename T> unsigned int Matrix<T>::_get2DIdx(const unsigned int& x, const unsigned int& y) const {
    return x * _rows + y;
}


#endif//MATRIX_IMPL_H
