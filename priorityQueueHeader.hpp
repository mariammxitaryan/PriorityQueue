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
    T parent(int);
    T leftChild(int);
    T rightChild(int);

public:
    PriorityQeueu();
    ~PriorityQueue();

    template <typename R>
    void push_range(R&&);

    template <typename Args>
    void emplace(Args&&...);

    void push(T);
    void pop();
    T top() const;
    bool isEmpty() const;
    int size() const;
    void clear();
    void print() const;
    void swap(const PriorityQueue<T>&);
};

#include "priorityQueueHeader.tpp"

#endif