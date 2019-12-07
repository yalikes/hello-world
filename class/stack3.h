#ifndef STACK3_H
#define STACK3_H
class Stack{
    struct Link
    {
        void* data;
        Link* next;
        Link(void *data,Link* next);
        ~Link();
    }*head;
public:
    Stack();
    ~Stack();
    void push(void *data);
    void* peek();
    void*pop();
};
#endif