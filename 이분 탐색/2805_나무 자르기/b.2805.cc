#include <iostream>
#include <algorithm>
using namespace std;

int arr[10000000];
long long N, M, num, ans,maxnum;

void wood()
{
	maxnum = 0;
	long long left = 0, right = 1000000000;
	while (left <= right)
	{
		ans = (left + right) / 2;
		num = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] > ans)
			{
				num += (arr[i] - ans);
			}
		}
		if (num < M)
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
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	wood();
	return 0;
}
