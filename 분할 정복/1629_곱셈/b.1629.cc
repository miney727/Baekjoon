#include <iostream>

using namespace std;

long long pow(long long x, long long y,long long z)
{
	long long num = 1;
	while (y > 0)
	{
		if (y % 2)
		{
			y--;
			num *= x;
			num %= z;
		}
		y /= 2;
		x *= x;
		x %= z;
	}
	return num;
}

int main()
{
	long long A, B, C;
	cin >> A >> B >> C;
	cout << pow(A, B, C) << endl;
	return 0;
}
