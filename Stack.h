#pragma once
#include <vector>
class Stack
{
    protected:
    std::vector<int> valuesVector;
    public:
    bool isEmpty();
    void push(int value);
    void pop();
    int top();
    int average();
};