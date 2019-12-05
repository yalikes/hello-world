#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int main(int argc,char** argv)
{
	vector<string> v;
	ifstream in("vector_practice.cpp");
	string line;
	while(in>>line)
		v.push_back(line);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}

