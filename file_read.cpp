#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char** argv)
{
	ifstream in("file_read.cpp");
	string s,line;
	while(getline(in,line))
		s+=line+"\n";
	cout<<s;
}
