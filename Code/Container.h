#include <iostream>
// This is basically an Abstract Class for stack and queue
// Uses runtime Polymorphism
class Container
{
public:
    virtual void insert(int elem) = 0;
    virtual int remove() = 0;
    virtual bool empty() = 0;
};