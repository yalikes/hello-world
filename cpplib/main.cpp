#include"clib.h"
#include<iostream>
using namespace std;
int main(int argc,char** argv)
{
    CStash int_stash;
    CStash char_stash;
    initialize(&int_stash,sizeof(int));
    initialize(&char_stash,sizeof(char));
    int a=42;
    int* int_p;
    char c='h';
    char* char_p;
    add(&int_stash,
    reinterpret_cast<const unsigned char*>(&a));
    add(&char_stash,
    reinterpret_cast<const unsigned char*>(&c));
    int_p=reinterpret_cast<int*>(fetch(&int_stash,0));
    char_p=reinterpret_cast<char*>(fetch(&char_stash,0));
    cout<<*int_p<<endl;
    cout<<*char_p<<endl;
}