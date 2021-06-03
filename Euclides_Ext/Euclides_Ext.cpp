#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ modulo (ZZ a,ZZ n, char val)
{
	//a = q*n + r  //0 =< r < n
	ZZ q, r;

	q = a / n;
    r = a - (q * n);

	if (r<0)
	{
		q = q-1;
		r = a -(a / n) * n;
	}

	if (val=='q')
    {
        return q;
    }
    else if (val == 'r')
    {
        return r;
    }

}
ZZ euclides (ZZ x, ZZ y, bool pasos)
{
	ZZ q,r;
	q = modulo(x,y,'q');
	r = modulo(x,y,'r');

	while (r!=0)
	{
		x = y;
		y = r;
		q = modulo(x,y,'q');
		r = modulo(x,y,'r');
		x = q*y + r;
		if (pasos == true)
        {
            cout<< x <<"="<< q <<"*"<< y <<"+"<< r <<endl;
            cout<<"======================================================="<<endl;
        }
	}
	return y;
}
ZZ euclidesext(ZZ a, ZZ b)
{
	//d = a*x + b*y;
	ZZ r1,r2,s1,s2,t1,t2,d;
	r1 = a;
	r2 = b;
	s1 = 1;
	s2 = 0;
	t1 = 0;
	t2 = 1;
	d = euclides(a,b,false);
	ZZ r, s, t;

	while (r2>0)
	{
		ZZ q ;
		q = r1 / r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;

		s = s1 - (q*s2);
		s1 = s2;
		s2 = s;

		t = t1 - (q*t2);
		t1 = t2;
		t2 = t;
		/*cout<<"r1: "<<r1<<endl;
		cout<<"r2: "<<r2<<endl;
		cout<<"r: "<<r<<endl;

		cout<<"s1: "<<s1<<endl;
		cout<<"s2: "<<s2<<endl;
		cout<<"s: "<<s<<endl;

		cout<<"t1: "<<t1<<endl;
		cout<<"t2: "<<t2<<endl;
		cout<<"t: "<<t<<endl;
		cout<<"======================================================="<<endl;*/
		cout<<d<<"="<<a<<"*"<<s1<<"+"<<b<<"*"<<t1<<endl;
		cout<<"======================================================="<<endl;
	}
	cout<<"x = "<<s1<<endl;
	cout<<"y = "<<t1<<endl;
	return s1;
}

int main(){

    ZZ a,b,c,d;
	a = 4095;
	b = 3110;
	d = euclides(a,b,false);

	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;

	cout<<"Euclides extendido: "<<endl;
	cout<<d<<" = "<<a<<"*x + "<<b<<"*y"<<endl;
	cout<<"======================================================="<<endl;
	euclidesext(a,b);

}

