// "Copyright 2019 <Khachatryan A.A.>"

#pragma once
#ifndef STACKL_STACKL_H_20191208
#define STACKL_STACKL_H_20191208

#include<sstream>
class StackL {
 public:
     struct Node {
         Node* next{ nullptr };
         float val{ 0 };
     };
     StackL() = default;
     StackL(const StackL& lhs);
     ~StackL();
     StackL& operator=(const StackL& lhs);
     void push(const float value);
     void pop();
     float& top();
     const float& top()const;
     bool is_empty()const;
 private:
     Node* top_{ nullptr };
};

#endif // STACKL_STACKL_H_20191208


