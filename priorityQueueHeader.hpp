#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include <stdexcept>
 
template <typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    void heapifyUp(int);
    void heapifyDown(int);
    int parent(int) const;
    int leftChild(int) const;
    int rightChild(int) const;

public:
    PriorityQueue() = default;
    ~PriorityQueue() = default;

    template <typename R>
    void push_range(R&&);

    template <typename... Args>
    void emplace(Args&&...);

    void push(T);
    void pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
    void clear();
    void print() const;
    void swap(PriorityQueue<T>&);
};

#include "priorityQueueImplementation.tpp"

#endif