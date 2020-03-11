#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000];
long long N, K, num, ans,maxnum;

void LAN_cable()
{
	maxnum = 0;
	long long left = 0, right = 2147483648;
	while (left <= right)
	{
		ans = (left + right) / 2;
		num = 0;
		for (int i = 0; i < K; i++)
		{
			num += arr[i] / ans;
		}
		if (num < N)
		{
			right = ans - 1;
		}
		else
		{
			maxnum = max(maxnum, ans);
			left = ans + 1;
		}
	}
	cout << maxnum << endl;

}

int main()
{
	
	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	LAN_cable();
	return 0;
	

}
