#include"cpplib.h"
#include"clib.h"
#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char** argv)
{
    Stash int_stash;
    CStash s;
    cout<<"sizeof Stash is"<<sizeof(int_stash)<<endl;
    cout<<"sizeof CStash is"<<sizeof(s)<<endl;
    int_stash.initialize(sizeof(int));
    for(int i=0;i<100;i++)
    {
        int_stash.add(reinterpret_cast<const unsigned char*>(&i));
    }
    for(int j=0;j<int_stash.count();j++)
        cout<<"intStash.fetch("<<j<<") == "
            <<*reinterpret_cast<int*>(int_stash.fetch(j))
            <<endl;
    Stash string_stash;
    const int bufsize = 80;
    string_stash.initialize(sizeof(char)*bufsize);
    ifstream in("cpplibTest.cpp");
    string line;
    while(getline(in,line))
        string_stash.add(reinterpret_cast<const unsigned char*>(line.c_str()));
	int k = 0;
	char* cp;
	while ((
			cp=reinterpret_cast<char*>(string_stash.fetch(k++))
		)!=nullptr)
	{
		cout << "string_stash.fetch(" << k << ")=" << cp << endl;
	}
	int_stash.cleanup();
	string_stash.cleanup();
}