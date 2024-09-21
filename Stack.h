#pragma once
#include <vector>
class Stack
{
    protected:
    std::vector<int> valuesVector;
    public:
    bool isEmpty();
        /*
        Check if stack is empty
        Parameters:
            None

        Returns:
            bool
        */
    void push(int value);
        /*
        Push value to top of stack
        Parameters:
            int value: Integer to be added to stack

        Returns:
            None
        */
    void pop();
        /*
        Pop value from top of stack
        Parameters:
            None

        Returns:
            None
        */
    int top();
        /*
        Returns value at top of stack
        Parameters:
            None

        Returns:
            int topValue
        */
    double average();
        /*
        Calculate average value of stack as a double
        Parameters:
            None

        Returns:
            double average
        */
};