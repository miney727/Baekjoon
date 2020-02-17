#include <iostream>
#include <algorithm>
using namespace std;

int hab[100000] = { 0, };

int main()
{
	int n, num;
	int maxhab = -10000000;
	cin >> n;
	int *number = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		number[i] = num;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			hab[i] += number[j];
			if (maxhab < hab[i])
			{
				maxhab = hab[i];
			}
			if (hab[i] < 0)
			{
				i = j;
				break;
			}
		}
	}
	cout << maxhab << endl;
	return 0;
}
