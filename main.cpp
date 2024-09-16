#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

int main()
{
    std::cout << "Implementation of a Linked List" << std::endl;
    LinkedList<int>* lst = new LinkedList<int>;
    std::cout << "Testing empty list construction: " << std::endl;
    if (lst->getHead() == nullptr){
        std::cout << "\tPassed empty head" << std::endl;
    }
    if (lst->getTail() == nullptr){
        std::cout << "\tPassed empty tail" << std::endl;
    }
    lst->insert(0,1);
    lst->insert(1,2);
    std::cout << lst->front() << "-" << lst->back() << std::endl;
    lst->insert(1,3);
    for (auto i = lst->begin(); i != lst->end(); ++i)
    {
        std::cout << *i << std::endl;
    }
    std::cout << lst->find(1) << "-" << lst->find(2) << "-" << lst->find(3) << std::endl;
    lst->remove(1);
    lst->print();
}