#include"clib.h"
#include<iostream>
#include<cassert>
using namespace std;
const int increment=100;
void initialize(CStash* s, size_t size)
{
    s->size=size;//size of echo element
    s->quantity=0;
    s->storage=NULL;
    s->next=0;
}
int add(CStash* s,const unsigned char* element)
{
    if(s->next>=s->quantity)
        inflate(s,increment);
    int startBytes = s->next * s->size;
    unsigned char* e=const_cast<unsigned char*>(element);
    for(int i=0;i<s->size;i++)
        s->storage[startBytes+i]=e[i];
    s->next++;
    return (s->next-1);
}
unsigned char* fetch(CStash* s,int index)
{
    assert(0<=index);
    if(index>=s->next)
        return NULL;
    return &(s->storage[index*s->size]);
}
int count(CStash *s)
{
    return s->size;
}
void inflate(CStash* s, int increment)
{
    assert(increment>0);
    int newQuantity=s->quantity+increment;
    int newBytes=newQuantity*s->size;
    int oldBytes=s->quantity*s->size;
    unsigned char*b =new unsigned char[newBytes];
    for(int i=0;i<oldBytes;i++)
        b[i]=s->storage[i];
    delete[] (s->storage);
    s->storage=b;
    s->quantity=newQuantity;
}
void cleanup(CStash*s)
{
    if(s->storage!=NULL)
    {
        cout<<"freeing storage"<<endl;
        delete[]s->storage;
    }
}