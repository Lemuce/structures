// Copyright 2019 by Khachatryan Artyom
#pragma once
#ifndef DynArrayT_H
#define DynArrayT_H

#include<cstddef>
#include<algorithm>
#include<stdexcept>

template<typename T>
class DynArrayT {
 public:
     DynArrayT();
     DynArrayT(const DynArrayT& arr);
     DynArrayT(DynArrayT&& arr);
     explicit DynArrayT(const std::ptrdiff_t size);
     DynArrayT& operator=(const DynArrayT& arr);
     DynArrayT& operator=(DynArrayT&& arr);
     ~DynArrayT();
     std::ptrdiff_t size() const;
     std::ptrdiff_t capacity() const;
     T& operator[] (const std::ptrdiff_t ind);
     const T& operator[](const std::ptrdiff_t ind) const;
     void push_back(const T& el);
     void push_back(T&& el);
     void pop_back();
     void resize(std::ptrdiff_t size);
     T* begin();
     T* end();
     const T* begin()const;
     const T* end()const;
 private:
     std::ptrdiff_t size_{ 0 }, capacity_{ 0 };
     T* data_{ nullptr };
};

template<typename T>
DynArrayT<T>::DynArrayT() = default;

template<typename T>
DynArrayT<T>::DynArrayT(const DynArrayT & arr) {
    capacity_ = arr.capacity_;
    size_ = arr.size_;
    data_ = new T[arr.capacity_];
    std::copy(arr.begin(), arr.end(), data_);
}

template<typename T>
DynArrayT<T>::DynArrayT(DynArrayT && arr) {
    capacity_ = arr.capacity_;
    size_ = arr.size_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    arr.capacity_ = arr.size_ = 0;
}

template<typename T>
DynArrayT<T>::DynArrayT(const std::ptrdiff_t size)
    : size_(size)
    , capacity_(size)
    , data_(new T[size])
{
    std::fill(begin(), end(), 0);
}

template<typename T>
DynArrayT<T>& DynArrayT<T>::operator=(const DynArrayT & arr) {
    if (data_ == arr.data_) return *this;
    delete[] data_;
    size_ = arr.size_;
    capacity_ = arr.capacity_;
    data_ = new T[capacity_];
    std::copy(arr.begin(), arr.end(), data_);
    return *this;
}

template<typename T>
DynArrayT<T>& DynArrayT<T>::operator=(DynArrayT && arr) {
    size_ = arr.size_;
    capacity_ = arr.capacity_;
    data_ = arr.data_;
    arr.data_ = nullptr;
    arr.size_ = arr.capacity_ = 0;
    return *this;
}

template<typename T>
DynArrayT<T>::~DynArrayT() {
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
std::ptrdiff_t DynArrayT<T>::size() const {
    return size_;
}

template<typename T>
std::ptrdiff_t DynArrayT<T>::capacity() const {
    return capacity_;
}

template<typename T>
T& DynArrayT<T>::operator[] (const std::ptrdiff_t ind) {
    if (ind < 0 || ind >= size_) throw std::out_of_range("");
    return data_[ind];
}

template<typename T>
const T& DynArrayT<T>::operator[] (const std::ptrdiff_t ind) const {
    if (ind < 0 || ind >= size_) throw std::out_of_range("");
    return data_[ind];
}

template<typename T>
void DynArrayT<T>::push_back(const T& el) {
    if (capacity_ == size_) {
        T* tmp = new T[capacity_ * 2];
        capacity_ *= 2;
        std::copy(begin(), end(), tmp);
        data_ = tmp;
    }
    data_[size_] = el;
    size_++;
}

template<typename T>
void DynArrayT<T>::push_back(T&& el) {
    if (capacity_ == size_) {
        if (capacity_ == 0) {
            capacity_ = 1;
        }
        else {
            capacity_ *= 2;
        }
        T* tmp = new T[capacity_];
        std::copy(begin(), end(), tmp);
        data_ = tmp;
    }
    data_[size_] = std::move(el);
    size_++;
}

template<typename T>
void DynArrayT<T>::pop_back() {
    if (size_ != 0) {
        size_--;
    }
}

template<typename T>
void DynArrayT<T>::resize(std::ptrdiff_t size) {
    if (size < 0) throw std::invalid_argument("");
    if (capacity_ >= size) {
        size_ = size;
    }
    else {
        T* tmp = new T[size];
        std::copy(begin(), end(), tmp);
        std::fill(tmp + size_, tmp + size, 0);
        delete[] data_;
        data_ = tmp;
        size_ = size;
        capacity_ = size;
    }
}

template<typename T>
T* DynArrayT<T>::begin() {
    return data_;
}

template<typename T>
T* DynArrayT<T>::end() {
    return data_ + size_;
}

template<typename T>
const T* DynArrayT<T>::begin() const {
    return data_;
}

template<typename T>
const T* DynArrayT<T>::end() const {
    return data_ + size_;
}


#endif  // ! DynArrayT_H
