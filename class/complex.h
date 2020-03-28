namespace paohui
{
	class complex
	{
		double re,im;
	public:
		complex(double r,double i):re{r},im{i}{}
		complex(double r):re{r},im{0}{}
		complex():re{0},im{0}{}

		double real() const {return re;}
		void read(double d){re=d;}
		double imag()const {return im;}
		void imag(double d){im=d;}

		double amplitude();
		
		complex& operator+=(complex z);
		complex& operator-=(complex z);
		complex& operator*=(complex z);
		complex& operator/=(complex z);
	};
	complex operator+(complex a,complex b);
	complex operator-(complex a,complex b);
	complex operator-(complex a);
	complex operator*(complex a,complex b);
	complex operator/(complex a,complex b);
	bool operator==(complex a,complex b);
	bool operator!=(complex a,complex b);
}
