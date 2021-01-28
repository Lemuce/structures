// "Copyright 2019 <Khachatryan A.A.>"

#pragma once
#ifndef StackA_StackA_H_20191208
#define StackA_StackA_H_20191208

#include<sstream>
class StackA {
public:
    StackA() = default;
    StackA(const StackA& lhs);
    ~StackA();
    StackA& operator=(const StackA& lhs);
    void push(const float value);
    void pop();
    float& top();
    const float& top()const;
    bool is_empty()const;
    float* begin();
    float* end();
    const float* begin() const;
    const float* end() const;
private:
    float* data_{ nullptr };
    ptrdiff_t size_{ 0 }, capacity_{ 0 };
};

#endif // StackA_StackA_H_20191208


