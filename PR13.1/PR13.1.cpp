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