#include <iostream>
#include "LinkedList.h" // Include your LinkedList header
#include "Stack.h"

int main() {
    // Create an empty LinkedList
    LinkedList<int> lst;

    std::cout << "Created an empty LinkedList." << std::endl;

    // Push elements to the front
    lst.push_front(10);
    lst.push_front(20);
    lst.push_front(30);
    std::cout << "After push_front(30), push_front(20), push_front(10): ";
    lst.print();

    // Push elements to the back
    lst.push_back(40);
    lst.push_back(50);
    std::cout << "After push_back(40), push_back(50): ";
    lst.print();

    // Check the front and back elements
    std::cout << "Front element: " << lst.front() << std::endl;
    std::cout << "Back element: " << lst.back() << std::endl;

    // Pop front and back elements
    lst.pop_front();
    std::cout << "After pop_front(): ";
    lst.print();

    lst.pop_back();
    std::cout << "After pop_back(): ";
    lst.print();

    // Insert element at index 1
    lst.insert(1, 25);
    std::cout << "After insert(1, 25): ";
    lst.print();

    // Try popping from the empty list
    try {
        LinkedList<int> emptyList;
        emptyList.pop_front();
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception on empty pop_front: " << e.what() << std::endl;
    }

    // Copy constructor test
    LinkedList<int> copiedList(lst);
    std::cout << "Copied list using copy constructor: ";
    copiedList.print();

    // Test iterators
    std::cout << "Iterating through the list using iterators: ";
    for (LinkedList<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    std::cout << "TESTING STACK IMPLEMENTATION" << std::endl;
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    std::cout << stk.top() << std::endl;
    stk.pop();
    std::cout << stk.top() << std::endl;
    stk.pop();
    std::cout << stk.top() << std::endl;
    stk.pop();
    std::cout << stk.top() << std::endl;
    stk.pop();
    std::cout << stk.top() << std::endl;
    // Destructor will be automatically called at the end of scope for each list
    return 0;
}