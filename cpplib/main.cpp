#include<iostream>
#include<cstdbool>
using namespace std;

int int_comp(int *a,int *b);
int char_comp(char*a,char*b);
void move(unsigned char*t,unsigned char*s,int size)
{
    for(int i=0;i<size;i++)
    {
        t[i]=s[i];
    }    
}
void exchange(unsigned char*s,unsigned char*t,int size)
{
    unsigned char* tem=new unsigned char[size];
    move(tem,s,size);
    move(s,t,size);
    move(t,tem,size);
    delete[] tem;
}
void my_qsort(unsigned char* eList,int n,int element_size,
              int (*comp)(unsigned char *a,unsigned char *b))
{
    if(n<=1)
        return;
    unsigned char* splitor=new unsigned char[element_size];
    move(splitor,eList,element_size);

    int lower=0;
    for(int i=0;i<n;i++)
    {
        if(comp(splitor,&eList[i*element_size])>=0)
        {
            exchange(eList+lower*element_size,
                     eList+i*element_size,element_size);
            lower++;
        }
    }
    delete[] splitor;
    my_qsort(eList+element_size,lower-1,element_size,comp);

    unsigned char* tem=new unsigned char[element_size];

    for(int i=1;i<lower;i++)
    {
        if(comp(eList+(i-1)*element_size,eList+i*element_size)<=0)
        {
            break;
        }
        else
        {
            exchange(eList+(i-1)*element_size,
            eList+i*element_size,element_size);
        }
    }
    my_qsort(eList+lower*element_size,n-lower,element_size,comp);
}
int main()
{
    char s[]="hello world";
    int i_array[]={2,3,476,23,421,123,21421,64,234,6,234,12,345,24,190
                    ,90,28,90,23};
    int n=11;
    my_qsort((unsigned char*)s,n,sizeof(char),
    (int (*)(unsigned char *a,unsigned char*b))char_comp);
    my_qsort((unsigned char*)i_array,19,sizeof(int),
             (int (*)(unsigned char*a,unsigned char*b))int_comp);
    cout<<s<<endl;
    for(int i:i_array)
    {
        cout<<i<<endl;
    }
    char a='a',b='b';
}
int int_comp(int *a,int *b)
{
    if(*a>*b)
        return 1;
    else if(*a==*b)
        return 0;
    else
        return -1;
}
int char_comp(char*a,char*b)
{
    if(*a>*b)
        return 1;
    else if(*a==*b)
        return 0;
    else
        return -1;
}
