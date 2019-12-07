#include<iostream>
#include<cstdlib>
#include"stash2.h"
using namespace std;
int main(int argc,char** args)
{
	Stash int_stash(sizeof(int));
	for(int i=0;i<100;i++)
	{
		int tem=rand()%100;;
		int_stash.add(reinterpret_cast<unsigned char*>(&tem));
	}
	for(int i=0;i<int_stash.count();i++)
	{
		cout<<"fetch("<<i<<")="<<*reinterpret_cast<int*>
		(int_stash.fetch(i))<<endl;
	}
	return 0;
}
