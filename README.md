---

# Priority Queue (Max-Heap) in C++

This project implements a **Priority Queue** using a **Max-Heap** data structure in C++. The priority queue provides an efficient way of managing a collection of elements with priority-based access, ensuring that the element with the highest priority (i.e., the maximum value) is always at the top.

## Table of Contents

- [Features](#features)
- [Data Structure](#data-structure)
- [Functions](#functions)
  - [push()](#push)
  - [push_range()](#push_range)
  - [emplace()](#emplace)
  - [top()](#top)
  - [pop()](#pop)
  - [isEmpty()](#isempty)
  - [size()](#size)
  - [clear()](#clear)
  - [print()](#print)
  - [swap()](#swap)
  - [heapifyUp()](#heapifyup)
  - [heapifyDown()](#heapifydown)
- [Usage](#usage)
- [Build and Compile](#build-and-compile)

## Features

- **Push operation**: Add an element to the priority queue while maintaining the heap property.
- **Push Range**: Insert a range of elements and ensure the heap property is maintained.
- **Emplace operation**: Construct and insert an element in-place, ensuring the heap property.
- **Top element**: Get the element with the highest priority.
- **Pop operation**: Remove the top element (highest priority) and restore the heap property.
- **Size and Empty Check**: Check the size of the queue or if it is empty.
- **Clear the Queue**: Remove all elements from the priority queue.
- **Swap**: Swap the contents of two priority queues.
- **Heapify operations**: Maintain the heap property using `heapifyUp` and `heapifyDown` functions.

## Data Structure

The priority queue is implemented using a **Max-Heap**, where the largest element is at the root. The heap is stored in a dynamic array (a vector in C++). The primary operations, such as insertion and deletion, run in **O(log n)** time complexity.

### Structure:
- **Vector-based storage**: The heap is stored in a `std::vector<T>` for dynamic resizing.
- **Heapify-up and heapify-down operations**: These are used to maintain the heap property after insertions and deletions.

## Functions

### push()
```cpp
void push(T value);
```
Adds a new element to the priority queue while maintaining the heap property.

### push_range()
```cpp
template <typename R>
void push_range(R&& range);
```
Adds a range of elements to the priority queue and restores the heap property.

### emplace()
```cpp
template <typename... Args>
void emplace(Args&&... args);
```
Constructs an element in-place and adds it to the queue while maintaining the heap property.

### top()
```cpp
T top() const;
```
Returns the element with the highest priority (the root of the heap). Throws an exception if the queue is empty.

### pop()
```cpp
void pop();
```
Removes the top element (highest priority) and restores the heap property.

### isEmpty()
```cpp
bool isEmpty() const;
```
Returns `true` if the priority queue is empty, otherwise `false`.

### size()
```cpp
int size() const;
```
Returns the number of elements in the priority queue.

### clear()
```cpp
void clear();
```
Removes all elements from the priority queue.

### print()
```cpp
void print() const;
```
Prints the elements of the priority queue.

### swap()
```cpp
void swap(PriorityQueue<T>& other);
```
Swaps the contents of two priority queues.

### heapifyUp()
```cpp
void heapifyUp(int index);
```
Restores the heap property by bubbling up the element at the given index.

### heapifyDown()
```cpp
void heapifyDown(int index);
```
Restores the heap property by bubbling down the element at the given index.

---

## Usage

### Example:

```cpp
#include "priorityQueueHeader.hpp"

int main() {
    PriorityQueue<int> pq;

    // Push elements to the priority queue
    pq.push(10);
    pq.push(15);
    pq.push(5);
    pq.push(20);

    // Print priority queue
    std::cout << "Priority Queue after push operations: ";
    pq.print();

    // Get the top element
    std::cout << "Top element: " << pq.top() << std::endl;

    // Pop the top element
    pq.pop();
    std::cout << "Priority Queue after pop: ";
    pq.print();

    // Check if the priority queue is empty
    std::cout << "Is the priority queue empty? " << (pq.isEmpty() ? "Yes" : "No") << std::endl;

    // Check the size of the priority queue
    std::cout << "Size of the priority queue: " << pq.size() << std::endl;

    // Clear the priority queue
    pq.clear();
    std::cout << "Priority Queue after clear: ";
    pq.print();

    return 0;
}
```

### Output:
```plaintext
Priority Queue after push operations: 20 15 10 5 
Top element: 20
Priority Queue after pop: 15 10 5 
Is the priority queue empty? No
Size of the priority queue: 3
Priority Queue after clear:
```

## Build and Compile

To compile the project, make sure you have a C++11 or higher compatible compiler. Use the following command to compile and run the program:

```bash
g++ -std=c++11 main.cpp -o priorityQueue
./priorityQueue
```

## Contributing

If you'd like to contribute to this project, feel free to fork it and submit a pull request. Suggestions for new features, bug fixes, and improvements are always welcome!
