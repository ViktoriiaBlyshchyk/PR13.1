//////////////////////////////////////////////////////////////////////////////
// PR13.1.cpp

#include <iostream>
#include <math.h>
#include <iomanip>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace std;

using namespace nsDod;
using namespace nsSum;
using namespace nsVar;

int main()
{
	cout << "x_p = "; cin >> x_p;
	cout << "x_k = "; cin >> x_k;
	cout << "dx = "; cin >> dx;
	cout << "e = "; cin >> e;
	cout << endl;

	cout << "-------------------------------------------------" << endl;
	cout << "|" << setw(5) << "x" << " |"
		<< setw(10) << "log((x + 1 * 1.) / (x - 1))" << " |"
		<< setw(5) << "s" << " |"
		<< setw(5) << "n" << " |"
		<< endl;
	cout << "-------------------------------------------------" << endl;

	x = x_p;
	while (x <= x_k) 
	{
		sum(); 

		cout << "|" << setw(7) << setprecision(2) << x << " |"
			<< setw(15) << setprecision(2) << log((x + 1 * 1.) / (x - 1)) << " |"
			<< setw(10) << setprecision(2) << s * 2 << " |"
			<< setw(10) << n << " |"
			<< endl;
		
		x += dx;
	}
	cin.get();
	return 0;
}

//////////////////////////////////////////////////////////////////////////////
// var.h

#pragma once
namespace nsVar 
{
	extern int n; 
	extern double x, x_p, x_k, dx, e, a, s;
};

//////////////////////////////////////////////////////////////////////////////
// var.cpp

namespace nsVar
{ 
	int n; 
	double x, x_p, x_k, dx, e, a, s;
};

//////////////////////////////////////////////////////////////////////////////
// dod.h

#pragma once
namespace nsDod 
{
	void dod();
};

//////////////////////////////////////////////////////////////////////////////
// dod.cpp

#include "dod.h"
#include "var.h" 

using namespace nsVar;

void nsDod::dod() 
{
	a *= (2 * n - 1 * 1.) / ((x * x) * (2 * n + 1)); 
} 

//////////////////////////////////////////////////////////////////////////////
// sum.h

#pragma once
namespace nsSum 
{
	void sum();
};

//////////////////////////////////////////////////////////////////////////////
// sum.cpp

#include <math.h>

#include "dod.h"
#include "sum.h"
#include "var.h" 

using namespace nsDod;
using namespace nsVar;

void nsSum::sum() 
{
	n = 0;
	a = 1. / x;
	s = a;
	do 
	{
		n++;
		dod(); 
		s += a;
	} 
	while (fabs(a) > e);
}