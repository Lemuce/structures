// "Copyright 2019 <Khachatryan A.A.>"
#pragma once
#ifndef MATRIXA_MATRIXA_H_20191108
#define MATRIXA_MATRIXA_H_20191108

#include<sstream>
#include<algorithm>
class MatrixA {
 public:
     MatrixA() = default;
     MatrixA(const MatrixA& lhs);
     MatrixA(MatrixA&& lhs) = default;
     MatrixA(std::ptrdiff_t col_count, std::ptrdiff_t row_count);
     MatrixA& operator=(MatrixA&& lhs) = default;
     ~MatrixA() = default;
     MatrixA& operator=(const MatrixA& lhs);
     std::ptrdiff_t col_count()const;
     std::ptrdiff_t row_count()const;
     float& at(std::ptrdiff_t row_i, std::ptrdiff_t col_i);
     const float& at(std::ptrdiff_t row_i, std::ptrdiff_t col_i)const;
 private:
     std::unique_ptr<float[]> data_{ nullptr };
     std::ptrdiff_t n_row_{ 0 }, n_col_{ 0 };
};

#endif // !MATRIXA_MATRIXA_H_20191108