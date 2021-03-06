#include <iostream>
#include <sstream>
#include <NTL/ZZ.h>
#include <stdio.h>

using namespace std;
using namespace NTL;

string zToString(ZZ z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ radixNotation(ZZ n, ZZ b)
{
    while (n >= b)
    {
        n = n / b;
    }
    return n;
}

ZZ mod(ZZ a, ZZ b)
{
    ZZ r;
    r = a - b * (a / b);
    r = r + (r < 0) * b;
    return r;
}

ZZ classicEuclides(ZZ a, ZZ b)
{    
    ZZ r;
    if (a >= b)
    {
        while (b != 0)
        {
            r = mod(a, b);
            a = b;
            b = r;
        }
        return a;
    }
    else
    {
        return ZZ(-1);
    }
}

ZZ lehmerGCD(ZZ x, ZZ y, ZZ b)
{
    ZZ x1, y1;
    ZZ A, B, C, D;
    while (y >= b)
    {
        //x1 = stoi(string(zToString(x), 0, 3));
        //y1 = stoi(string(zToString(y), 0, 3));
        x1 = radixNotation(x, b);
        y1 = radixNotation(y, b);
        A = 1;
        B = 0;
        C = 0;
        D = 1;
        ZZ q, q1;
        while ((y1 + C) != 0 && (y1 + D) != 0)
        {
            q = ((x1 + A) / (y1 + C));
            q1 = ((x1 + B) / (y1 + D));
            //cout << "y1 + C: " << y1 + C << endl;
            //cout << "y1 + D: " << y1 + D << endl;
            //cout << "x: " << x << "\ty: " << y << "\tx1: " << x1 << '\t' << "y1: " << y1 << "\tA: " << A << "\tB: " << B  << "\tC: " << C << "\tD: " << D << "\tq:" << q << "\tq1: " << q1 << endl;
            if (q != q1) break;
            ZZ t = A - (q * C);
            A = C;
            C = t;
            t = B - (q * D);
            B = D;
            D = t;
            t = x1 - (q * y1);
            x1 = y1;
            y1 = t;
        }
        //cout << endl;
        ZZ T;
        if (B == 0 || (q != 0 && q1 != 0))
        {
            T = mod(x, y);
            x = y;
            y = T;
            //cout << "Entro al if\n";
        }
        else
        {
            ZZ u;
            T = (A * x) + (B * y);
            u = (C * x) + (D * y);
            x = T;
            y = u;
            //cout << "Entro al else\n";
        }
        //cout << x << '\t' << y << endl;
        //string abc;
        //cin >> abc;
        //cout << endl;
    }
    return classicEuclides(x, y);
}

int main()
{
        a = conv<ZZ>("113961491159425124522547710339601516414581636984912436254300859090699424230641");
	    b = conv<ZZ>("83825486427085367934112210589772991484453445136409752382569536656995452034661");
        ZZ b;
        b = 1000;
        ZZ res = lehmerGCD(x, y, b);
}
