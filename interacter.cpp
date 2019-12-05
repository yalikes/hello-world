#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	const int line_length=200;
	string pre="powershell -Command ";
	char icommand[line_length];
	while(true)
	{
		cout<<">>>";
		cin.getline(icommand,line_length);
		if (strcmp(icommand,"exit")==0)
		{
			cout << "bye" << endl;
			break;
		}
		system((pre+icommand).c_str());
	}
}


