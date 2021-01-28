// "Copyright 2019 <Khachatryan A.A.>"

#include<matrixa/matrixa.h>

MatrixA::MatrixA(const MatrixA& lhs) {
    data_.reset(new float[lhs.n_col_ * lhs.n_row_]);
    std::copy(lhs.data_.get(), lhs.data_.get() + lhs.n_row_ * lhs.n_col_, data_.get());
    n_col_ = lhs.n_col_;
    n_row_ = lhs.n_row_;
}

MatrixA::MatrixA(std::ptrdiff_t col_count, std::ptrdiff_t row_count) {
    if (col_count <= 0 || row_count <= 0) throw std::invalid_argument("");
    data_.reset(new float[col_count * row_count]);
    n_col_ = col_count;
    n_row_ = row_count;
    std::fill(data_.get(), data_.get() + n_col_ * n_row_, 0);
}

MatrixA& MatrixA::operator=(const MatrixA& lhs) {
    n_row_ = lhs.n_row_;
    n_col_ = lhs.n_col_;
    std::copy(lhs.data_.get(), lhs.data_.get() + lhs.n_row_ * lhs.n_col_, data_.get());
    return *this;
}

std::ptrdiff_t MatrixA::col_count()const {
    return n_col_;
}

std::ptrdiff_t MatrixA::row_count()const {
    return n_row_;
}

float& MatrixA::at(std::ptrdiff_t row_i, std::ptrdiff_t col_i) {
    if (row_i >= row_count() || row_i < 0 || col_i < 0
        || col_i >= col_count())throw std::invalid_argument("");
    return data_.get()[row_i * n_col_ + col_i];
}

const float& MatrixA::at(std::ptrdiff_t row_i, std::ptrdiff_t col_i)const {
    if (row_i >= row_count() || row_i < 0 || col_i < 0
        || col_i >= col_count())throw std::invalid_argument("");
    return data_.get()[row_i * n_col_ + col_i];
}
