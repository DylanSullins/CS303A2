#include <stdexcept>
#include "Stack.h"


bool Stack::isEmpty()
{
    return (valuesVector.empty());
}
void Stack::push(int value)
{
    valuesVector.push_back(value);
}
void Stack::pop()
{
    valuesVector.pop_back();
}
int Stack::top()
{
    if (isEmpty()) throw std::out_of_range("Error: Attempting to access empty stack.");
    return valuesVector.back();
}
int Stack::average()
{
    if (isEmpty()) return 0;
    int total = 0;
    int count = valuesVector.size();
    for (int i = 0; i < count; ++i)
    {
        total += valuesVector.at(i);
    }
    return total / count;
    // Returns an integer, check to see if it needs to be float instead
}