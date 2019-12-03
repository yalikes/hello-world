#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string pre="powershell -Command ";
	char icommand[100];
	while(true)
	{
		cout<<">>>";
		cin.getline(icommand,100);
		if (strcmp(icommand,"exit")==0)
		{
			cout << "bye" << endl;
			break;
		}
		system((pre+icommand).c_str());
	}
}
