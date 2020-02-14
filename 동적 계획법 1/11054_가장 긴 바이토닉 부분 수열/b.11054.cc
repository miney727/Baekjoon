#include <iostream>
using namespace std;
int N;
int arr[1001] = { 0, };
int leng1[1001] = { 0, };
int leng2[1001] = { 0, };
void maxlength()
{
	int max;
	for (int j = 1; j <= N; j++) //증가 부분
	{
		max = 0;
		for (int i = 1; i <= j-1; i++)
		{
			if (arr[j] > arr[i]&&max<leng1[i])
			{
				max = leng1[i];
			}
		}
		leng1[j] = max + 1;
	}

	for (int j = N; j>=1; j--) //감소 부분
	{
		max = 0;
		for (int i = N; i >=j+1; i--)
		{
			if (arr[j] > arr[i] && max<leng2[i])
			{
				max = leng2[i];
			}
		}
		leng2[j] = max + 1;
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
		if (maxnum < leng1[i]+leng2[i])
		{
			maxnum = leng1[i] + leng2[i];
		}
	}
	cout << maxnum-1 << endl; //중복되므로 1감소
	return 0;
}
