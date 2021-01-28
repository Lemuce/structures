// "Copyright 2019 <Khachatryan A.A.>"

#pragma once
#ifndef QUEUEL_QUEUEL_H_20191214
#define QUEUEL_QUEUEL_H_20191214

#include<stdexcept>

class QueueL {
public:
    QueueL();
    QueueL(const QueueL& rhs);
    ~QueueL();
    QueueL& operator=(const QueueL& rhs);
    void push(const float value);
    void pop();
    bool is_empty() const;
    float& top();
    const float& top() const;
private:
    struct Node {
        float val;
        Node* next{nullptr};
    };
    void DeleteAllNodes();
    Node* top_{ nullptr };
    Node* last_{ nullptr };
};

#endif // QUEUEL_QUEUEL_H_20191214
