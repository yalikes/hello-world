#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> iv;
	cout<<hex<<(long)main<<endl;
	for(int i=0;i<10;i++)
		iv.push_back(i);
	for(int i=0;i<iv.size();i++)
		cout<<iv[i]<<(i<iv.size()-1?", ":"");
	cout<<endl;
	for(int i=0;i<iv.size();i++)
		iv[i]*=10;
	for(int i=0;i<iv.size();i++)
		cout<<iv[i]<<(i<iv.size()-1?", ":"");
	cout<<endl;
}
