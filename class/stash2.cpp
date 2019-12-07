#include"stash2.h"
#include<iostream>
using namespace std;
const int increment=100;

Stash::Stash(int size)
{
    this->size=size;
    quantity=0;
    next=0;
    storage=nullptr;
}
int Stash::add(unsigned char* element)
{
    if(next>=quantity)
        inflate(increment);
    int startBytes = next *size;
    for(int i=0;i<size;i++)
    {
        storage[startBytes+i]=element[i];
    }
    next++;
    return next-1;
}

unsigned char*Stash::fetch(int index)
{
    if(index >= next)
        return nullptr;
    return &(storage[index*size]);
}
int Stash::count()
{
    return next;
}
void Stash::inflate(int incrase)
{
    int new_quantity = quantity+incrase;
    int new_bytes=new_quantity*size;
    int old_bytes=quantity*size;
    unsigned char* b=new unsigned char[new_bytes];
    for(int i=0;i<old_bytes;i++)
    {
        b[i]=storage[i];
    }
    delete[] storage;
    storage=b;
    quantity=new_quantity;
}
Stash::~Stash()
{
    if(storage!=nullptr)
    {
        cout<<"freeing storage"<<endl;
        delete[] storage;
    }
}