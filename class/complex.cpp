#include"complex.h"
#include<cmath>

paohui::complex& paohui::complex::operator+=(complex z)
{
    re+=z.re;
    im+=z.im;
    return *this;
}
paohui::complex& paohui::complex::operator-=(complex z)
{
    re-=z.re;
    im-=z.im;
    return *this;
}

bool paohui::operator==(complex a,complex b)
{
	return a.real()==b.real() && a.imag() == b.imag();
}


bool paohui::operator!=(complex a,complex b)
{
    return !(a==b);
}

paohui::complex paohui::operator+(complex a,complex b){return a+=b;}
paohui::complex paohui::operator-(complex a,complex b){return a-=b;}
paohui::complex paohui::operator-(complex a){return {-a.real(),-a.imag()};}
paohui::complex paohui::operator*(complex a,complex b){return a*=b;}
paohui::complex paohui::operator/(complex a,complex b){return a/=b;}

double paohui::complex::amplitude()
{
    return std::sqrt( re*re+im*im);
}
paohui::complex& paohui::complex::operator*=(complex a)
{
    re=re*a.real()-im*a.imag();
    im=re*a.imag()+im*a.real();
    return *this;
}
paohui::complex& paohui::complex::operator/=(complex z)
{
    double denominator=z.amplitude()*z.amplitude();
    double t_re=re/denominator;
    double t_im=im/denominator;
    re=t_re*z.real()+t_im*z.imag();
    im=-t_re*z.imag()+t_im*z.real();
    return *this;
}