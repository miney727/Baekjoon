#include <iostream>
using namespace std;
int main()
{
	int arr[11];
	int n, k, num;
	int ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >>num;
		arr[i] = num;
	}
	
	while (k>0)
	{
		num = 0;
		for (int i = 1; i <= n; i++)
		{
			if (num <= arr[i] && arr[i] <= k)
			{
				num = arr[i];
			}
		}
		k -= num;
		ans++;
	}
	cout << ans << endl;
}
