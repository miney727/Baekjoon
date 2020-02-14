#include <iostream>
using namespace std;
int N;
int arr[1001] = { 0, };
int leng[1001] = { 0, };
void maxlength()
{
	int max;
	for (int j = 1; j <= N; j++)
	{
		max = 0;
		for (int i = 1; i <= j-1; i++)
		{
			if (arr[j] > arr[i]&&max<leng[i])
			{
				max = leng[i];
			}
		}
		leng[j] = max + 1;
	}
}
int main()
{
	int num;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	maxlength();
	int maxnum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (maxnum < leng[i])
		{
			maxnum = leng[i];
		}
	}
	cout << maxnum << endl;
	return 0;
}
