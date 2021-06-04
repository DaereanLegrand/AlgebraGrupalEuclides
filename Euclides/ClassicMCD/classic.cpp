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

int main(){

    ZZ a,b,c,d;
	a = conv<ZZ>(38783);
	b = conv<ZZ>(38299);
	d = euclides(a, b);
}

