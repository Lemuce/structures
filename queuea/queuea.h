// "Copyright 2019 <Khachatryan A.A.>"

#pragma once
#ifndef QUEUEL_QUEUEA_H_20191214
#define QUEUEL_QUEUEA_H_20191214

#include<cstddef>
#include<algorithm>
#include<iostream>
class QueueA {
 public:
     QueueA();
     QueueA(const QueueA& lhs);
     ~QueueA();
     void push(const float value);
     void pop();
     float& top();
     const float& top()const;
     bool is_empty()const;
 private:
     float* data_{ nullptr };
     std::ptrdiff_t capacity_{ 0 }, size_{ 0 };
     float* begin_{ nullptr };
     float*end_{ nullptr };
     
};

#endif // QUEUEL_QUEUEL_H_20191214