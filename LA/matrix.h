#pragma once
#include <stdexcept>

template<class T> class matrix {
private:
    T** data;
    size_t n, m;

public:
    matrix(size_t n) :n(n), m(n) {
        this->data = new T*[n];
        for (size_t i = 0; i < n; ++i)
            data[i] = new T[n];
    }
    matrix(size_t m, size_t n) : n(n), m(m) {
        this->data = new T*[m];
        for (size_t i = 0; i < m; ++i)
            data[i] = new T[n];
    }
    
    friend matrix<T> operator*(matrix<T> A, matrix<T> B) {
        if ((A.n != B.m) || (A.m != B.n)) throw std::invalid_argument("Matrix Size mismatch");
        matrix<T> result(A.m, B.n);

        for (size_t i = 0; i < B.n; i++) {
            for (size_t j = 0; j < A.n; j++) {
                for (size_t k = 0; k < A.n; k++) {
                    result.data[j][i] += A.data[j][k] * B.data[k][i];
                }
            }
        }
    }
};

