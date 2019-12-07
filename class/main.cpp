#include<iostream>
#include<fstream>
#include"stack3.h"
using namespace std;

int main(int argc,char** args)
{
	ifstream in("main.cpp");
	Stack string_s;
	string line;
	while(getline(in,line))
	{
		string_s.push(new string(line));
	}
	string* s;
	while((s=(string*)string_s.pop())!=nullptr)
	{
		cout<<*s<<endl;
		delete s;
	}
	return 0;
}
