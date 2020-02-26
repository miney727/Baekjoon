#include <iostream>

using namespace std;

long long mat[2][2] = { { 0, 1 }, { 1, 2 } };
long long fibo[2][2] = { { 0, 1 }, { 1, 1 } };
void fibonacci(long long a)
{

	long long result[2][2] = { { 1, 0 }, { 0, 1 } };
	long long temp2[2][2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			temp2[i][j] = 0;
		}
	}
	while (a > 0)
	{
		if (a % 2)
		{
			a--;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						temp2[i][j] += (result[i][k] * fibo[k][j]) % 1000000;

					}
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					result[i][j] = temp2[i][j];
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					temp2[i][j] = 0;
				}
			}
		}
		else
		{
			a /= 2;
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						temp2[i][j] += (fibo[i][k] * fibo[k][j]) % 1000000;
					}
				}
			}
			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					fibo[i][j] = temp2[i][j];
				}
			}
			for (int i = 0; i <2; i++)
			{
				for (int j = 0; j <2; j++)
				{
					temp2[i][j] = 0;
				}
			}

		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				temp2[i][j] += (mat[i][k] * result[k][j]) % 1000000;
			}
		}
	}
	cout << temp2[0][0] << endl;
}
int main()
{

	long long n;
	cin >> n;
	fibonacci(n);
	return 0;
}
