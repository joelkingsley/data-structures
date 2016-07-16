#ifndef QUEUE
#define QUEUE

class queue
{
    struct Node
    {
        char data;
        Node *next;
    };
    Node *front;
    Node *rear;
public:
    queue();
    ~queue();
    void enqueue(char x);
    char dequeue();
    void traverse();
};

#endif // QUEUE

