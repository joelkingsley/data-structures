#ifndef STACK
#define STACK

class stack
{
private:
    struct Node
    {
        char data;
        Node *next;
    };
    Node* top;
public:
    stack();
    ~stack();
    char retTop(void);
    void push(char x);
    char pop();
};
#endif // STACK

