namespace paohui
{
class Vector
{
private:
    double* elem;
    int sz;
public:
Vector(int s):elem{new double[s]},sz{s}
{}
~Vector(){delete[] elem;}
double& operator[](int i);
int size() const;
};
}