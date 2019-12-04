#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream in("file_open.cpp");
	ofstream out("file_open.txt");
	string s;
	while(getline(in,s))
		out<<s<<endl;
}
