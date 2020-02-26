#include <iostream>

using namespace std;

long long N, B, num;
int** mat;
int result[5][5];
void powmatrix(long long a)
{
	int temp2[5][5];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			temp2[i][j] = 0;
		}
	}
	while (a > 0)
	{
		if (a % 2)
		{
			a--;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < N; k++)
					{
						temp2[i][j] += (result[i][k] * mat[k][j]) % 1000;

					}
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					result[i][j] = temp2[i][j];
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					temp2[i][j] = 0;
				}
			}
		}
		else
		{
			a /= 2;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					for (int k = 0; k < N; k++)
					{
						temp2[i][j] += (mat[i][k] * mat[k][j]) % 1000;
					}
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					mat[i][j] = temp2[i][j];
				}
			}
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					temp2[i][j] = 0;
				}
			}

		}
	}
	for (int i = 0; i < N; i++) //출력
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j]%1000 << " ";
		}
		cout << endl;
	}
}
int main()
{
	cin >> N >> B;
	mat = new int*[N];
	for (int i = 0; i < N; i++)
	{
		mat[i] = new int[N];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			mat[i][j] = num;
			result[i][j] = num;
		}
	}
	powmatrix(B-1);
	return 0;
}
