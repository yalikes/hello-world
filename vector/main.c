#include<stdio.h>
#define P(EX) printf("%s %d",#EX,EX);
int main()
{
	int a=10;
	int b=32;
	P(a+b)
}
