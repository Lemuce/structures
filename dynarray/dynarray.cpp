// Copyright 2019 by Khachatryan Artyom

#include<dynarray/dynarray.h>
#include<algorithm>
#include<stdexcept>


DynArray::DynArray() = default;


DynArray::DynArray(const DynArray & arr) {
    capacity_ = arr.capacity_;
    size_ = arr.size_;
    data_ = new float[arr.capacity_];
    std::copy(arr.begin(), arr.end(), data_);
}


DynArray::DynArray(DynArray && arr) {
    capacity_ = arr.capacity_;
    size_ = arr.size_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    arr.capacity_ = arr.size_ = 0;
}


DynArray::DynArray(const std::ptrdiff_t size)
    : size_(size)
    , capacity_(size)
    , data_(new float[size])
{
    std::fill(begin(), end(), 0);
}


DynArray& DynArray::operator=(const DynArray & arr) {
    if (data_ == arr.data_) return *this;
    delete[] data_;
    size_ = arr.size_;
    capacity_ = arr.capacity_;
    data_ = new float[capacity_];
    std::copy(arr.begin(), arr.end(), data_);
    return *this;
}


DynArray& DynArray::operator=(DynArray && arr) {
    size_ = arr.size_;
    capacity_ = arr.capacity_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    arr.size_ = arr.capacity_ = 0;
    return *this;
}


DynArray::~DynArray() {
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
}


std::ptrdiff_t DynArray::size() const {
    return size_;
}


std::ptrdiff_t DynArray::capacity() const {
    return capacity_;
}


float& DynArray::operator[] (const std::ptrdiff_t ind) {
    if (ind < 0 || ind >= size_) throw std::out_of_range("");
    return data_[ind];
}


const float& DynArray::operator[] (const std::ptrdiff_t ind) const {
    if (ind < 0 || ind >= size_) throw std::out_of_range("");
    return data_[ind];
}


void DynArray::push_back(const float& el) {
    if (capacity_ == size_) {
        float* tmp = new float[capacity_ * 2];
        capacity_ *= 2;
        std::copy(begin(), end(), tmp);
        data_ = tmp;
    }
    data_[size_] = el;
    size_++;
}


void DynArray::push_back(float&& el) {
    if (capacity_ == size_) {
        if (capacity_ == 0) {
            capacity_ = 1;
        }
        else {
            capacity_ *= 2;
        }
        float* tmp = new float[capacity_];
        std::copy(begin(), end(), tmp);
        data_ = tmp;
    }
    data_[size_] = std::move(el);
    size_++;
}


void DynArray::pop_back() {
    if (size_ != 0) {
        size_--;
    }
}


void DynArray::resize(std::ptrdiff_t size) {
    if (size < 0) throw std::invalid_argument("");
    if (capacity_ >= size ) {
        size_ = size;
    }
    else {
        float* tmp = new float[size];
        std::copy(begin(), end(), tmp);
        std::fill(tmp+size_, tmp + size, 0);
        delete[] data_;
        data_ = tmp;
        size_ = size;
        capacity_ = size;
    }
}


float* DynArray::begin() {
    return data_;
}


float* DynArray::end() {
    return data_ + size_;
}


const float* DynArray::begin() const {
    return data_;
}


const float* DynArray::end() const {
    return data_ + size_;
}