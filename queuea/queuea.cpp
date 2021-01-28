#include<queuea/queuea.h>
#include<algorithm>
QueueA::QueueA() = default;
QueueA::QueueA(const QueueA & lhs) {
    delete[] data_;
    data_ = new float[lhs.size_];
    std::copy(lhs.begin_, lhs.end_, data_);
    capacity_ = size_ = lhs.size_;
    begin_ = data_;
    end_ = data_ + size_ - 1;
}
QueueA::~QueueA() {
    delete data_;
}
void QueueA::push(const float value) {
    if (data_ == nullptr) {
        data_ = new float[1];
        capacity_ = 0;
        size_ = 1;
        begin_ = data_;
        end_ = data_;
        *end_ = value;
        return;
    }
    if (capacity_ == 0) {
        float* tmp = new float[size_ * 2];
        capacity_ = (size_);
        std::copy(begin_, end_, tmp);
        begin_ = tmp;
        end_ = tmp + size_ - 1;
        size_ = 2 * size_;
        delete[] data_;
        data_ = tmp;
    }
    end_++;
    capacity_--;
    *end_ = value;
}
void QueueA::pop() {
    if (begin_ != end_) {
        begin_++;
        size_--;
    }
    else {
        throw std::logic_error("");
    }
}
float& QueueA::top() {
    return *begin_;
}
const float& QueueA::top()const {
    return *begin_;
}
bool QueueA::is_empty()const {
    return (data_ == nullptr || begin_ == end_);
}