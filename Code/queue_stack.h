#include <iostream>
#include "Container.h"

using namespace std;

class Queue : public Container
{
    int queue[100], n = 100, front = 0, rear = 0;

public:
    void insert(int elem)
    {
        if (rear == n - 1)
            cout << "Queue Overflow" << endl;
        else
        {
            queue[rear] = elem;
            rear++;
        }
    }
    int remove()
    {
        if (front == rear)
        {
            cout << "Queue Underflow ";
            return 0;
        }
        else
        {
            front++;
            return queue[front - 1];
        }
    }
    void Display()
    {
        if (front == rear)
            cout << "Queue is empty" << endl;
        else
        {
            cout << "Queue elements are : ";
            for (int i = front; i <= rear; i++)
                cout << queue[i] << " ";
            cout << endl;
        }
    }
    bool empty()
    {
        if (front == rear)
            return true;
        return false;
    }
};

class Stack : public Container
{
    int S[100];          // S[45] is 46th element!
    int top = 0;            // current position in stack which is empty, position indicator
    int cardinality = 0;    // cardinality, no. of elements in the stack

public:
    void insert(int elem); // add an element on top of stack
    int remove();           // note the value at the top, remove the top and return the value
    int card();             // cardinality, how many elements in stack
    int front();       
    bool empty();
};

void Stack::insert(int elem)
{
    S[top] = elem;
    top++;
    cardinality++;
};

int Stack::remove()
{
    if (top == 0)
    {
        cout << "ERROR ";
        return 0;
    }
    else
    {
        top--;
        cardinality--;
        return S[top];
    }
};

int Stack::front()
{
    if (top == 0)
    {
        cout << "ERROR ";
        return 0;
    }
    else
    {
        return S[top-1];
    }
}

int Stack::card()
{
    return cardinality;
}

bool Stack::empty() 
{
    if(top==0) return true;
    return false;
}
