#pragma once
#include <vector>
class Stack
{
    protected:
    std::vector<int> valuesVector;
    public:
    bool isEmpty();
    void push(int value);
    int pop();
    int top();
    int average();
};