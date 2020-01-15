#include <iostream>
using namespace std;
int main()
{
	int x1, x2, x3, temp;
	while (1)
	{
		cin >> x1 >> x2 >> x3;
		if (x1 == 0 && x2 == 0 && x3 == 0)
		{
			break;
		}
		if (x3 < x1)
		{
			temp = x3;
			x3 = x1;
			x1 = temp;
		}
		if (x3 < x2)
		{
			temp = x3;
			x3 = x2;
			x2 = temp;
		}
		if (x1*x1 + x2*x2 == x3*x3)
		{
			cout << "right\n";
		}
		else
		{
			cout << "wrong\n";
		}
	}

	return 0;
}
