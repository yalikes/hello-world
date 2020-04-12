#include<iostream>
#include"p_vector.h"
class A
{
    double *elem;
    size_t sz;
public:
    A(size_t size):sz{size},elem{new double[size]}{}
    ~A(){delete[] elem;}

    A(A&& a):elem{a.elem},
    sz{a.sz}
    {
        std::cout<<"move"<<std::endl;
        a.elem=nullptr;
        a.sz=0;
    }
    const int size()
    {
        return sz;
    }
};
A inc(A a)
{
    A res(a.size());
    return res;
}
int main()
{
    using namespace paohui;
    using namespace std;

}