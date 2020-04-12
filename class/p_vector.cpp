#include"p_vector.h"
#include<algorithm>
double& paohui::Vector::operator[](int i)
{
    return elem[i];
}



paohui::Vector::Vector(std::initializer_list<double> lst)
    :elem{new double[lst.size()]},sz{(int)lst.size()}
{
    std::copy(lst.begin(),lst.end(),elem);
}
int  paohui::Vector::size() const
{
return sz;
}


paohui::Vector::Vector(const Vector& a)
    :elem{new double[a.sz]},sz{a.size()}
{
    for(int i=0;i<a.size();i++)
    {
        elem[i]=a.elem[i];
    }
}
paohui::Vector& paohui::Vector::operator=(const Vector& a)
{ 
    double* p=new double[a.sz];
    for(int i=0;i!=a.sz;++i)
        p[i]=a.elem[i];
    delete[] elem;
    elem=p;
    sz=a.sz;
    return *this;
}