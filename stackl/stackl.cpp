// "Copyright 2019 <Khachatryan A.A.>"
#include<stackl/stackl.h>
    StackL::StackL(const StackL& lhs) {
        if (lhs.top_ != nullptr) {            
            Node* cur = top_ = new Node{nullptr,lhs.top()};
            for (Node* tmp = lhs.top_->next; tmp!= nullptr;tmp=tmp->next) {
                cur->next = new Node{ nullptr, tmp->val };
                cur = cur->next;
            }
        }
    }
    StackL::~StackL() {
        while (top_ != nullptr) pop();
    }
    StackL& StackL::operator=(const StackL& lhs) {
        if (lhs.top_ != nullptr && lhs.top_!=top_) {
            while (top_ != nullptr) {
                pop();
            }
            Node* cur = top_ = new Node{ nullptr,lhs.top() };
            for (Node* tmp = lhs.top_->next; tmp != nullptr; tmp = tmp->next) {
                cur->next = new Node{ nullptr, tmp->val };
                cur = cur->next;
            }
        }
        if (lhs.top_ == nullptr) {
            while (top_ != nullptr) {
                pop();
            }
        }
        return *this;
    }
    void StackL::push(const float value) {
        top_ = new Node{ top_,value };
    }
    void StackL::pop() {
        if (top_==nullptr)
        {
            return;
        }
        Node* next = top_->next;
        delete top_;
        top_ = next;
    }
    float& StackL::top() {
        return  top_->val;
    }
    const float& StackL::top()const {
        return top_->val;
    }
    bool StackL::is_empty()const {
        if (top_ == nullptr) return true;
        return false;
    }



