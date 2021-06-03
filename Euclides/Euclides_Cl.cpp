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

int main(){

    ZZ a,b,c,d;
	a = 4095;
	b = 3110;

	cout<<"a: "<<a<<endl;
	cout<<"b: "<<b<<endl;


	cout<<"Euclides Clasico: "<<endl;
	cout<<a<<"= q*"<<b<<" + r"<<endl;
	cout<<"======================================================="<<endl;
	d = euclides(a, b, true);
    cout<<"Mcd: "<<d<<endl;
}

