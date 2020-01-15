#include <iostream>

#define M_PI 3.14159265358979323846
using namespace std;

int main()
{
	double r;
	cin >> r;
	cout << fixed;
	cout.precision(6);
	cout << r*r*M_PI << "\n" << r*r * 2 << "\n";
	return 0;


}
