#include <stdexcept>
#include "Stack.h"


bool Stack::isEmpty()
    /*
    Check if stack is empty
    Parameters:
        None

    Returns:
        bool
    */
{
    return (valuesVector.empty());
}
void Stack::push(int value)
    /*
    Push value to top of stack
    Parameters:
        int value: Integer to be added to stack

    Returns:
        None
    */
{
    valuesVector.push_back(value);
}
void Stack::pop()
    /*
    Pop value from top of stack
    Parameters:
        None

    Returns:
        None
    */
{
    valuesVector.pop_back();
}
int Stack::top()
    /*
    Returns value at top of stack
    Parameters:
        None

    Returns:
        int topValue
    */
{
    if (isEmpty()) throw std::out_of_range("Error: Attempting to access empty stack.");
    return valuesVector.back();
}
double Stack::average()
    /*
    Calculate average value of stack as a double
    Parameters:
        None

    Returns:
        double average
    */
{
    if (isEmpty()) return 0;
    double total = 0.0;
    int count = valuesVector.size();
    for (int i = 0; i < count; ++i)
    {
        total += valuesVector.at(i);
    }
    return total / static_cast<double>(count);
}