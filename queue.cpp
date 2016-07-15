#include <iostream>
#include <cstdio>
#include "queue.h"

using namespace std;

queue::queue()
{
    front = rear = NULL;
}

queue::~queue()
{
    if(front!=NULL)
    {
        Node *temp;
        temp = front;
        while(temp!=NULL)
        {
            front = front->next;
            delete temp;
            temp = front;
        }
        rear = NULL;
    }
}

void queue::enqueue(char x)
{
    Node *n = new Node;
    n->data = x;
    n->next = NULL;
    if(front == NULL)
    {
        front = n;
        rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }
}

char queue::dequeue()
{
    if(front == NULL)
    {
        cout << "\nQueue Overflow";
    }
    Node *temp;
    char k;
    temp = front;
    k = front->data;
    if(front->next == NULL)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
    }
    delete temp;
    return k;
}

void queue::traverse()
{
    Node *temp;
    temp = front;
    while(temp!=NULL)
    {
        cout<< temp->data;
        temp = temp->next;
    }
}
