#include<stacka/stacka.h>
#include<algorithm>
#include<exception>
StackA::StackA(const StackA& lhs) {
    capacity_ = lhs.capacity_;
    size_ = lhs.size_;
    data_ = new float[lhs.capacity_];
    std::copy(lhs.begin(), lhs.end(), data_);
}
StackA::~StackA() {
    delete[] data_;
}
StackA& StackA::operator=(const StackA& lhs) {
    if (data_ == lhs.data_) return *this;
    delete[] data_;
    capacity_ = lhs.capacity_;
    size_ = lhs.size_;
    data_ = new float[lhs.capacity_];
    std::copy(lhs.begin(), lhs.end(), data_);
}
void StackA::push(float value) {
    if (capacity_ == 0) {
        data_ = new float[1];
        capacity_ = 1;
    }
    if (capacity_ == size_) {
        float* tmp = new float[capacity_ * 2];
        std::copy(begin(), end(), tmp);
        delete[] data_;
        data_ = tmp;
        capacity_ = capacity_ * 2;
    }
    data_[size_] = value;
    size_++;
}
void StackA::pop() {
    if (is_empty()) return;
    size_--;
}
float& StackA::top() {
    if (is_empty()) throw std::length_error("");
    return data_[size_ - 1];
}
const float& StackA::top()const {
    if (is_empty()) throw std::length_error("");
    return data_[size_ - 1];
}
bool StackA::is_empty()const {
    return size_ == 0;
}
float* StackA::begin() {
    return data_;
}
float* StackA::end() {
    return data_ + size_;
}
const float* StackA::begin() const {
    return data_;
}
const float* StackA::end() const {
    return data_ + size_;
}