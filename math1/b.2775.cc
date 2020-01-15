#include <iostream>
using namespace std;

int main()
{
	int T;
	int a[15][15] = { 0};  // 층, 호수
	cin >> T;
	int k, n;
	for (int j = 0; j < T; j++)
	{
		cin >> k >> n;
		for (int m = 1; m <= n; m++)  //0층 n호까지
		{
			a[0][m] = m;
		}



		for (int l = 1; l <= k; l++)
		{
			for (int m = 1; m <= n; m++)
			{
				if (a[l][m] == 0)
				{
					for (int z = 1; z <= m; z++)
					{

						a[l][m] += a[l - 1][z];    //0으로 만들자

					}
				}
			}
		}
		cout << a[k][n] << endl;

	}
	

	return 0;
}