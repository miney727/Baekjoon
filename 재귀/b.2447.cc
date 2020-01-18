
#include <iostream>
using namespace std;
void star(int n, int x, int y);
char paint[2188][2188];
int main()

{
	for (int i = 0; i < 2188; i++)        //그림판을 *로 초기화
	{
		for (int j = 0; j < 2188; j++)
		{
			paint[i][j] = '*';
		}
	}
	int N;
	cin >> N;
	star(N,0,0);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout <<paint[i][j];
		}
		cout << endl;
	}
	return 0;
}
void star(int n,int x, int y)
{
	if (n == 3)                //기저 사례
	{
		paint[x+1][y+1] = ' ';
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == 1 && j == 1)               //가운데 구멍 뚫기
			{
				for (int l = -1; l < 2; l++)
				{
					for (int k = -1; k < 2; k++)
					{
						star(n / 3, x + i * n / 3+l, y + j * n / 3+k);
					}
				}
			}
			else
			{
				star(n/3,x+ i*n/3,y+ j*n/3);
			}


		}
	}


}
