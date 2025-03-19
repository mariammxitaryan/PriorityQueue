
#include "priorityQueueHeader.hpp"

int main() {
    PriorityQueue<int> pq1;

    //Test push function
    pq1.push(10);
    pq1.push(20);
    pq1.push(5);
    pq1.push(15);
    std::cout << "Priority Queue after push operations: ";
    pq1.print();

    //Test top function
    std::cout << "Top element: " << pq1.top() << std::endl;

    //Test pop function
    pq1.pop();
    std::cout << "Priority Queue after pop: ";
    pq1.print();

    //Test isEmpty function
    std::cout << "Is the priority queue empty? " << (pq1.isEmpty() ? "Yes" : "No") << std::endl;

    //Test size function
    std::cout << "Size of the priority queue: " << pq1.size() << std::endl;

    //Test emplace function
    pq1.emplace(25);
    pq1.emplace(8);
    std::cout << "Priority Queue after emplace: ";
    pq1.print();

    //Test push_range function
    std::vector<int> values = {30, 12, 18};
    pq1.push_range(values);
    std::cout << "Priority Queue after push_range: ";
    pq1.print();

    //Test clear function
    pq1.clear();
    std::cout << "Priority Queue after clear: ";
    pq1.print();

    //Test swap function
    PriorityQueue<int> pq2;
    pq2.push(50);
    pq2.push(60);
    pq2.push(40);

    std::cout << "Before swap - PQ1: ";
    pq1.print();
    std::cout << "Before swap - PQ2: ";
    pq2.print();

    pq1.swap(pq2);
    
    std::cout << "After swap - PQ1: ";
    pq1.print();
    std::cout << "After swap - PQ2: ";
    pq2.print();

    return 0;
}

