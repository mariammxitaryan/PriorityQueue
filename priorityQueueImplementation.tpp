#include "priorityQueueHeader.hpp"

// ------------------ push() ------------------ //
// Adds an element to the priority queue.
// The element is added at the end, and heapifyUp ensures the heap property is maintained.
template <typename T>
void PriorityQueue<T>::push(T value) {
    heap.push_back(value);  // Insert the new element at the end of the heap.
    heapifyUp(heap.size() - 1);  // Restore the heap property by bubbling up.
}

// ------------------ push_range() ------------------ //
// Adds a range of elements to the priority queue and ensures heap property is restored.
// It first inserts elements, then applies heapifyDown to all non-leaf nodes to restore the heap.
template <typename T>
template <typename R>
void PriorityQueue<T>::push_range(R&& range) {
    // Insert all elements in the range into the heap.
    for (const auto& elem : range) {
        heap.push_back(elem);
    }

    // Restore the heap property by applying heapifyDown starting from the last non-leaf node.
    for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
        heapifyDown(i);
    }
}

// ------------------ emplace() ------------------ //
// Constructs an element in-place and adds it to the priority queue.
// The new element is added at the end and then heapifyUp is called to maintain heap property.
template <typename T>
template <typename... Args>
void PriorityQueue<T>::emplace(Args&&... args) {
    heap.emplace_back(std::forward<Args>(args)...);  // Construct element in-place.
    heapifyUp(heap.size() - 1);  // Ensure heap property by bubbling the element up.
}

// ------------------ top() ------------------ //
// Returns the highest priority element (root of the heap).
// Throws an exception if the queue is empty.
template <typename T>
T PriorityQueue<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Priority queue is empty.\n");
    }
    return heap[0];  // The root of the heap is always the largest element.
}

// ------------------ pop() ------------------ //
// Removes the top element (highest priority) and re-balances the heap.
// It swaps the top with the last element, removes it, and restores heap property.
template <typename T>
void PriorityQueue<T>::pop() {
    if (heap.empty()) {
        throw std::out_of_range("PriorityQueue is empty!");
    }

    std::swap(heap[0], heap.back());  // Swap the top element with the last element.
    heap.pop_back();  // Remove the last element (old root).
    
    if (!heap.empty()) {
        heapifyDown(0);  // Restore the heap property from the root.
    }
}

// ------------------ isEmpty() ------------------ //
// Returns true if the priority queue is empty, otherwise false.
template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return heap.empty();  // Simply checks if the vector is empty.
}

// ------------------ size() ------------------ //
// Returns the number of elements in the priority queue.
template <typename T>
int PriorityQueue<T>::size() const {
    return heap.size();  // Simply returns the size of the vector.
}

// ------------------ clear() ------------------ //
// Clears all elements from the priority queue.
template <typename T>
void PriorityQueue<T>::clear() {
    heap.clear();  // Removes all elements from the vector.
}

// ------------------ print() ------------------ //
// Prints all elements in the priority queue.
template <typename T>
void PriorityQueue<T>::print() const {
    for (const T& val : heap) {
        std::cout << val << " ";  // Print each element separated by space.
    }
    std::cout << std::endl;  // Newline after printing all elements.
}

// ------------------ swap() ------------------ //
// Swaps the contents of this priority queue with another one.
template <typename T>
void PriorityQueue<T>::swap(PriorityQueue<T>& other) {
    std::swap(heap, other.heap);  // Swap the underlying heaps of both queues.
}

// ------------------ heapifyUp() ------------------ //
// Restores the heap property by bubbling up the element at the given index.
// It compares the element with its parent and swaps them if necessary until the heap property is restored.
template <typename T>
void PriorityQueue<T>::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        std::swap(heap[parent(index)], heap[index]);  // Swap with parent if out of order.
        index = parent(index);  // Move to the parent.
    }
}

// ------------------ heapifyDown() ------------------ //
// Restores the heap property by bubbling down the element at the given index.
// It compares the element with its children and swaps it with the largest child if necessary.
template <typename T>
void PriorityQueue<T>::heapifyDown(int index) {
    int left{leftChild(index)};
    int right{rightChild(index)};
    int largest{index};

    if (left < heap.size() && heap[left] > heap[largest]) {
        largest = left;  // Left child is larger than current.
    }

    if (right < heap.size() && heap[right] > heap[largest]) {
        largest = right;  // Right child is larger than the largest.
    }

    if (largest != index) {
        std::swap(heap[index], heap[largest]);  // Swap with the largest child.
        heapifyDown(largest);  // Continue the process down the heap.
    }
}

// ------------------ parent() ------------------ //
// Returns the index of the parent of the node at the given index.
template <typename T>
int PriorityQueue<T>::parent(int index) const { 
    return (index - 1) / 2;  // Parent index formula for a complete binary tree.
}

// ------------------ leftChild() ------------------ //
// Returns the index of the left child of the node at the given index.
template <typename T>
int PriorityQueue<T>::leftChild(int index) const { 
    return 2 * index + 1;  // Left child index formula.
}

// ------------------ rightChild() ------------------ //
// Returns the index of the right child of the node at the given index.
template <typename T>
int PriorityQueue<T>::rightChild(int index) const { 
    return 2 * index + 2;  // Right child index formula.
}
