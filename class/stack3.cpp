#include"stack3.h"
#include<iostream>
using namespace std;
Stack::Link::Link(void* data,Link* next)
{
    this->data=data;
    this->next=next;
}
Stack::Link::~Link(){}
Stack::Stack()
{
    head=nullptr;
}
void Stack::push(void *dat)
{
    head=new Link(dat,head);
}
void* Stack::peek()
{
    return head->data;
}
void* Stack::pop()
{
    if(head==nullptr)
        return nullptr;
    void* result=head->data;
    Link* old_head=head;
    head=head->next;
    delete old_head;
    return result;
}
Stack::~Stack(){}
