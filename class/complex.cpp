#include<complex.h>
#include<math.h>
double complex::amplitude()
{
    return sqrt( re*re+im*im);
}
complex& complex::operator*=(complex a)
{
    re=re*a.real()-im*a.imag();
    im=re*a.imag()+im*a.real();
    return *this;
}
complex& complex::operator/=(complex a)
{
    double denominator=a.amplitude()*a.amplitude();
    re=re/denominator;
    im=im/denominator;
    re=re*a.real()+im*a.imag();
    im=-re*a.imag()+im*a.real();
    return *this;
}