#include <iostream>
#include <stdexcept>
#include "LinkedList.h"

int main()
{
    std::cout << "Implementation of a Linked List" << std::endl;
    LinkedList<int>* lst = new LinkedList<int>;
    if (lst->getHead() == nullptr){
        std::cout << "Pass empty head" << std::endl;
    }
    if (lst->getTail() == nullptr){
        std::cout << "Pass empty tail" << std::endl;
    }

    lst->push_front(10);
    std::cout << lst->getNumItems() << std::endl;
    lst->push_front(20);
    std::cout << lst->getNumItems() << std::endl;
    lst->push_back(30);
    std::cout << lst->getNumItems() << std::endl;
    std::cout << lst->getHead()->data << std::endl;
    std::cout << lst->getHead()->next->data << std::endl;
    std::cout << lst->getTail()->data << std::endl;
    std::cout << std::endl;

    lst->pop_back();
    std::cout << lst->getNumItems() << std::endl;
    std::cout << lst->getTail()->data << std::endl;
    lst->pop_back();
    std::cout << lst->back() << std::endl;
    std::cout << lst->getNumItems() << std::endl;
    lst->pop_back();
    lst->push_back(10);
    std::cout << lst->back() << std::endl;
    try 
    {
        lst->pop_back();
        std::cout << lst->getNumItems() << std::endl;
    }
    catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
}