#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, temp,two = 0, five = 0;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		temp = i;
		while (temp % 2 == 0 || temp % 5 == 0)
		{
			if (temp%2)
			{
				five++;
				temp /= 5;
			}
			else
			{
				two++;
				temp /= 2;
			}
		}
	}
	cout << min(two, five) << endl;
}
