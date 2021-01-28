#pragma once

#include<queuel/queuel.h>
#include<iostream>
QueueL::QueueL() = default;
QueueL::QueueL(const QueueL & rhs) {
    for (Node* tmp = rhs.top_; tmp != nullptr; tmp = tmp->next) {
        push(tmp->val);
    }
}
QueueL::~QueueL() {
    DeleteAllNodes();
}
QueueL& QueueL::operator=(const QueueL & rhs) {
    if (rhs.top_ == top_ )return *this;
    DeleteAllNodes();
    for (Node* tmp = rhs.top_; tmp != nullptr; tmp = tmp->next) {
        push(tmp->val);
    }
    return *this;
}
void QueueL::push(const float value) {
    if (top_ == nullptr) {
        top_ = new Node;
        top_->val = value;
        last_ = top_;
        return;
    }
    last_ = last_->next = new Node;
    last_->val = value;
}
void QueueL::pop() {
    Node* tmp = top_;
    top_ = top_->next;
    delete tmp;
}
bool QueueL::is_empty()const {
    return top_ == nullptr;
}
float& QueueL::top() {
    return top_->val;
}
const float& QueueL::top() const {
    return top_->val;
}
void QueueL::DeleteAllNodes() {
    while (top_ != nullptr) {
        Node* tmp = top_;
        top_ = top_->next;
        delete tmp;
    }
}
