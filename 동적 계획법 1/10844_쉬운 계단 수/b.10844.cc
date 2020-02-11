#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long long digit[101][10] = { { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 } };
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0) //0일땐 1증가
			{
				digit[i][j + 1] += digit[i - 1][j] %= 1000000000;
			}
			else if (j == 9) //9일땐 8증가
			{
				digit[i][j - 1] += digit[i - 1][j] %= 1000000000;
			}
			else //나머진 +1이거나-1인수 증가
			{
				digit[i][j - 1] += digit[i - 1][j] %= 1000000000;
				digit[i][j + 1] += digit[i - 1][j] %= 1000000000;
			}
		}
	}
	long long sum = 0;
	for (int i = 0; i <= 9; i++) 
	{
		sum += digit[N - 1][i]; //다 더함
	}
	cout << sum % 1000000000 << endl;
	return 0;
}
