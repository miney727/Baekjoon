#include <iostream>
#include <algorithm>
using namespace std;

int arr[200000];
int N, M, num, ans,maxdis,prevnum;

void router()
{
	maxdis = 0;
	long long left = 1, right = arr[N-1]-arr[0];
	while (left <= right)
	{
		ans = (left + right) / 2;
		num = 1; //arr[0]에 하나 설치
		prevnum = arr[0];
		for (int i = 1; i < N; i++)
		{
			if (arr[i] - prevnum>=ans)
			{
				num++;
				prevnum = arr[i];
			}
		}
		if (num < M)
		{
			right = ans - 1;
		}
		else
		{
			maxdis = max(maxdis, ans);
			left = ans + 1;
		}
	}
	cout << maxdis << endl;
}

int main()
{
	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr + N);
	router();
	return 0;
	
}
