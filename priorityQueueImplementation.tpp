#include "priorityQueueHeader.hpp"

template <typename T>
void PriorityQueue<T>::push(T value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

template <typename T>
template <typename R>
void PriorityQueue<T>::push_range(R&& range) {
    for (const auto& elem : range) {
        heap.push_back(elem);
    }

    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}


template <typename T>
template <typename... Args>
void PriorityQueue<T>::emplace(Args&&... args) {
    heap.emplace_back(std::forward<Args>(args)...); 
    heapifyUp(heap.size() - 1);  
}

template <typename T>
T PriorityQueue<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Priority queue is empty.\n");
    }
    return heap[0];
}

template <typename T>
void PriorityQueue<T>::pop() {
    if (heap.empty()) {
        throw std::out_of_range("PriorityQueue is empty!");
    }

    std::swap(heap[0], heap.back());
    heap.pop_back();

    if (!heap.empty()) {
        heapifyDown(0);
    }
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return heap.empty();
}

template <typename T>
int PriorityQueue<T>::size() const {
    return heap.size();
}

template <typename T>
void PriorityQueue<T>::clear() {
    heap.clear();
}

template <typename T>
void PriorityQueue<T>::print() const {
    for (const T& val : heap) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void PriorityQueue<T>::swap(PriorityQueue<T>& other) {
    std::swap(heap, other.heap);  
}

template <typename T>
void PriorityQueue<T>::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

template <typename T>
void PriorityQueue<T>::heapifyDown(int index) {
    int left{leftChild(index)};
    int right{rightChild(index)};
    int largest{index};

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

template <typename T>
int PriorityQueue<T>::parent(int index) const { 
    return (index - 1) / 2; 
}

template <typename T>
int PriorityQueue<T>::leftChild(int index) const { 
    return 2 * index + 1; 
}

template <typename T>
int PriorityQueue<T>::rightChild(int index) const { 
    return 2 * index + 2; 
}
