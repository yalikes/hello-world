#include<initializer_list>
#include"p_container.h"
namespace paohui
{
class Vector:public Container
{
private:
    double* elem;
    int sz;
public:
Vector(int s):elem{new double[s]},sz{s}
{}
Vector(std::initializer_list<double> lst);

~Vector(){delete[] elem;}
double& operator[](int i);
int size() const;
};
}