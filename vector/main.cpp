#include<iostream>
using namespace std;
int sum(int a,int b);
int main()
{
	int(*func)(int a,int b);
	func=sum;
	int s=func(10,32);
	cout<<s<<endl;
}
int sum(int a,int b)
{
	return a+b;
}
