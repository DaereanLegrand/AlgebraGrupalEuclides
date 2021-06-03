#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <sstream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;

ZZ modulo (ZZ a,ZZ n)
{
	//a = q*n + r  //0 =< r < n
	ZZ q, r;

	if (r<0)
	{
		q = q-1;
		r = a -(a / n) * n;
	}
	else
	{
		q = a / n;
		r = a - (q * n);
	}
        return r;
}
ZZ euclides (ZZ x, ZZ y)
{
	ZZ q,r;
	q = x/y;
	r = modulo(x,y);

	while (r!=0)
	{
		x = y;
		y = r;
		q = x/y;
		r = modulo(x,y);
		x = q*y + r;
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
	d = euclides(a,b);
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
	d = euclides(a,b);

	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;

	cout<<"Euclides extendido: "<<endl;
	cout<<d<<" = "<<a<<"*x + "<<b<<"*y"<<endl;
	cout<<"======================================================="<<endl;
	euclidesext(a,b);

}

