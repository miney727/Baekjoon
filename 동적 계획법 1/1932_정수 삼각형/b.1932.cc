#include <iostream>
#include <algorithm> //max함수 사용
using namespace std;
int arr[500][500];
int hab[500][500]; //동적계획법

void tri(int n)
{
	hab[0][0] = arr[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0) //삼각형 왼쪽 끝
			{
				hab[i][j] = arr[i][j] + hab[i - 1][j]; 

			}
			else if (j == i)//삼각형 오른쪽 끝
			{
				hab[i][j] = arr[i][j] + hab[i - 1][j - 1];

			}
			else
			{
				hab[i][j] = arr[i][j] + max(hab[i - 1][j - 1], hab[i - 1][j]);
			}
		}
	}
	int maxnum = 0;
	for (int i = 0; i < n; i++)
	{
		maxnum =max(maxnum, hab[n - 1][i]); //가장 큰 값
	}
	cout << maxnum << endl; //출력
}
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j]; //입력
		}
	}
	tri(N);
	return 0;
}
