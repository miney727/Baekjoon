#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b,num;
	cin >> a >> b;
	if (a < b) //b가 더 작음
	{
		num = a;
		a = b;
		b = num;
	}
	for (int i = 1; i <= b; i++)
	{
		if (b%i == 0 && a%i == 0)
		{
			num = i;
		}
	}
	cout << num << endl;
	cout << a*b / num << endl;
	return 0;
}
