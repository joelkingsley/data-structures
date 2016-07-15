#include <iostream>
#include "stack.h"

using namespace std;

stack::stack()
{
    top = NULL;
}

stack::~stack()
{
    if(top!=NULL)
    {
        Node *temp = top;
        while(top!=NULL)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }
}

void stack::push(char x)
{
    Node *n = new Node;
    n->data = x;
    n->next = top;
    top = n;
}

char stack::pop()
{
    Node *temp = top;
    char t;
    top = top->next;
    t = temp->data;
    delete temp;
    return t;
}

inline char stack::retTop()
{
    return top->data;
}
