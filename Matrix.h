#ifndef MATRIX_H
#define MATRIX_H
#include "ArraySequence.h"

template <class T>
class Matrix
{
    private:
        ArraySequence<ArraySequence<T>> Matrix_basement
        size_t size; 
    public:
        Matrix()
        {
            ArraySequence<ArraySequence<T>> temporary_Matrix(0);
            Matrix_basement = temporary_Matrix;
        }
        Matrix(size_t size)
        {
            this->size = size; 
            ArraySequence<ArraySequence<T>> temporary_Matrix(size);
            for(size_t i =0; i< size; ++i )
            {
                ArraySequence<T> temporary_vector(size); 
                temporary_Matrix[i] = temporary_vector;
            }
            Matrix_basement = temporary_Matrix;
        }
        template<size_t m, size_t n>
        Matrix(T (&items)[m][n], size_t size)
        {
            this->size = size; 
            ArraySequence<ArraySequence<T>> temporary_Matrix(size);
            for(size_t i =0; i< size; ++i )
            {
                ArraySequence<T> temporary_vector(items[i], size); 
                temporary_Matrix[i] = temporary_vector;
            }
            Matrix_basement = temporary_Matrix;
        }
        void Set(size_t i, size_t j, T elem) {
            this->Matrix_basement.Get(i).Set(j, elem);
        }
        Matrix(const Matrix<T>& matrix) {
            Matrix_basement = matrix.Matrix_basement;
            size = matrix.getSize();
        };
        size_t const getSize() const {
            return size;
        }
        Matrix Add(const Matrix& other) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->Matrix_basement[i][j] += other.Matrix_basement[i][j];
                }
            }
            return *this;
        }
        Matrix Multiply(const int& k) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->Matrix_basement[i][j] *= k;
                }
            }
            return *this;
        }
        Matrix LineMultiply(const size_t& index, const int& k) {
            for (size_t j = 0; j != size; ++j) {
                this->Matrix_basement[index][j] *= k;
            }
            return *this;
        }
        Matrix Transponition() {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = i; j != size; ++j) {
                    T temporary_Matrix1 = Matrix_basement[i][j];
                    T temporary_Matrix2 = Matrix_basement[j][i];
                    this->Set(i, j, temporary_Matrix2);
                    this->Set(j, i, temporary_Matrix1);
                }
            }
            return *this;
        }
        Matrix SwapLines(const int& index1, const int& index2) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    swap(this->Matrix_basement[index1][j], this->Matrix_basement[index2][j]);
                }
            }
            return *this;
        }
        Matrix Multiply(const Matrix<T>& matrix) {
            if (matrix.getSize() != this->size)
                throw length_error("Lengths are not equals!");
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    int temporary_Matrix = 0;
                    for (size_t k = 0; k != size; ++k) {
                        temporary_Matrix += (*this)[i][k] * matrix[k][j];
                    }
                    this->Set(i, j, temporary_Matrix);
                }
            }
            return *this;
        }
        Matrix AddLineToLine(const int& index1, const int& index2, const int& k) {
            for (size_t i = 0; i != size; ++i) {
                for (size_t j = 0; j != size; ++j) {
                    this->Matrix_basement[index1][j] += this->Matrix_basement[index2][j] * k;
                }
            }
            return *this;
        }
        ArraySequence<T> operator[] (size_t index) const {
            return this->Matrix_basement[index];
        }
        Matrix<T>& operator= (const Matrix& other) {
            this->Matrix_basement = other.Matrix_basement;
            this->size = other.getSize();
            return *this;
        }
        Matrix<T> operator+ (const Matrix& other) const {
            Matrix<T> temporary_Matrix(this->getSize());
            temporary_Matrix = *this;
            return temporary_Matrix.Add(other);
        }
        Matrix<T> operator* (const int& k) const {
            Matrix<T> temporary_Matrix(this->getSize());
            temporary_Matrix = *this;
            return temporary_Matrix.Multiply(k);
        }
        Matrix<T> operator- (const Matrix& other) const {
            Matrix<T> temporary_Matrix(this->getSize());
            temporary_Matrix = *this;
            return temporary_Matrix.Add(other*(-1));
        }
};





#endif /* MATRIX_H */