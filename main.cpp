#include <iostream>
#include "LinkedList.h" // Include your LinkedList header
#include "Stack.h"

int main() {
    // DEMONSTRATION OF LINKED LIST
    std::cout << "TESTING LINKED LIST" << std::endl;
    std::cout << "\tCreating an empty list:" << std::endl;
    LinkedList<int> list;
    list.print();
    std::cout << "\tPushing 20 to an empty list:" << std::endl;
    list.push_back(20);
    list.print();
    std::cout << "\tPushing 10 front:" << std::endl;
    list.push_front(10);
    list.print();
    std::cout << "\tPushing 30 back:" << std::endl;
    list.push_back(30);
    list.print();
    std::cout << "\tFind 20:" << std::endl;
    std::cout << list.find(20) << std::endl;
    std::cout << "\tInserting 15 at index 1:" << std::endl;
    list.insert(1,15);
    list.print();
    std::cout << "\tFront: " << list.front() << std::endl;
    std::cout << "\tBack: " << list.back() << std::endl;
    std::cout << "\tRemoving 15 by index (1):" << std::endl;
    list.remove(1);
    list.print();
    std::cout << "\tPop_back until empty:" << std::endl;
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    list.pop_back();
    list.print();
    std::cout << "\tAttempt to pop_back on empty list:" << std::endl;
    try
    {
        list.pop_back();
    }
    catch (std::runtime_error& e)
    {
        std::cout << "\t\tCaught an error: " << e.what() << std::endl;
    }
    std::cout << "\tConcluding demonstration of linked list." << std::endl;
    std::cout << std::endl;
    // DEMONSTRATION OF STACK
    std::cout << "TESTING STACK" << std::endl;
    std::cout << "\tCreating stack:" << std::endl;
    Stack stack;
    std::cout << "\tTesting empty stack:" << std::endl;
    if (stack.isEmpty()) std::cout << "Empty Stack" << std::endl;
    else std::cout << "Stack not empty" << std::endl;
    std::cout << "\tPushing 4,5,6,7 to stack:" << std::endl;
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    std::cout << "\tAverage: " << stack.average() << std::endl;
    std::cout << "\tTop: " << stack.top() << std::endl;
    std::cout << "\tPopping: " << std::endl;
    stack.pop();
    std::cout << "\tAverage: " << stack.average() << std::endl;
    std::cout << "\tTop: " << stack.top() << std::endl;
    std::cout << "\tPopping: " << std::endl;
    stack.pop();
    std::cout << "\tAverage: " << stack.average() << std::endl;
    std::cout << "\tTop: " << stack.top() << std::endl;
    std::cout << "\tPopping: " << std::endl;
    stack.pop();
    std::cout << "\tAverage: " << stack.average() << std::endl;
    std::cout << "\tTop: " << stack.top() << std::endl;
    std::cout << "\tPopping: " << std::endl;
    stack.pop();
    std::cout << "\tAverage: " << stack.average() << std::endl;
    return 0;
}