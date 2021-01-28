// Copyright 2019 by Khachatryan Artyom
#pragma once
#ifndef DYNARRAY_H
#define DYNARRAY_H

#include<cstddef>
#include<algorithm>


class DynArray {
 public:
     DynArray();
     DynArray(const DynArray& arr);
     DynArray(DynArray&& arr);
     explicit DynArray(const std::ptrdiff_t size);
     DynArray& operator=(const DynArray& arr);
     DynArray& operator=(DynArray&& arr);
     ~DynArray();
     std::ptrdiff_t size() const;
     std::ptrdiff_t capacity() const;
     float& operator[] (const std::ptrdiff_t ind);
     const float& operator[](const std::ptrdiff_t ind) const;
     void push_back(const float& el);
     void push_back(float&& el);
     void pop_back();
     void resize(std::ptrdiff_t size);
     float* begin();
     float* end();
     const float* begin()const;
     const float* end()const;
 private:
     std::ptrdiff_t size_{ 0 }, capacity_{ 0 };
     float* data_{ nullptr };
};



#endif  // ! DYNARRAY_H
