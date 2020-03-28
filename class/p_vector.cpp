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