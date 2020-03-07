#include <iostream>

using namespace std;
int arr[1000001] = { 0, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, N,temp,num;
	cin >> M >> N;
	arr[1] = 1;
	for (int i = 2; i <= N; i++)
	{
		if (!arr[i])
		{
			num = 2;
			while (i*num <= N)
			{
				arr[i*num] = 1;
				num++;
			}
		}
	}
	for (int i = M; i <= N; i++)
	{
		if (arr[i] == 0)
		{
			cout << i << "\n";
		}
	}
	return 0;
}
