#include <iostream>

using namespace std;

int main()
{
	int** matrix1, **matrix2,**matrix3;
	int N, M, num, len1,len2;
	cin >> N >> M;
	matrix1 = new int*[N];
	len1 = N;
	for (int i = 0; i < N; i++)
	{
		matrix1[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			matrix1[i][j] = num;
		}
	}
	cin >> N >> M;
	len2 = M;
	matrix2 = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix2[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> num;
			matrix2[i][j] = num;
		}
	}
	matrix3 = new int*[len1];
	for (int i = 0; i < len1; i++)
	{
		matrix3[i] = new int[len2];
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			matrix3[i][j] = 0;
		}
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			for (int k = 0; k < N; k++)
			{
				matrix3[i][j] += (matrix1[i][k]*matrix2[k][j]);
			}
		}
	}
	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			cout << matrix3[i][j] << " ";
		}
		cout << endl;
	}
	delete(matrix1);
	delete(matrix2);
	delete(matrix3);
	return 0;
}
