#include <iostream>
using namespace std;

int main()
{

	int arr[1001] = { 0, };
	int n, p,num,k,l;
	long long t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		arr[i] = p;
	}
	l = n;

	while (l-->0)
	{
		num = 1000;
		for (int i = 1; i <= n; i++)
		{
			if (arr[i] <= num)
			{
				num = arr[i];
				k = i;
			}
		}
		arr[k] = 1001;
		t += num*(l+1);
	}
	cout << t << endl;
	return 0;
}
