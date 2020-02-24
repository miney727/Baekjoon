#include <iostream>

using namespace std;

int arr[129][129];
int white = 0, blue = 0;
void paper(int x,int y,int leng)
{
	int temp = arr[x][y];
	bool pure = true;
	for (int i = x; i < x + leng; i++)
	{
		for (int j = y; j < y + leng; j++)
		{
			if (temp != arr[i][j]&&pure)//순수하지 않을시 4등분
			{
				paper(x, y, leng / 2);
				paper(x+leng/2, y, leng / 2);
				paper(x, y+leng/2, leng / 2);
				paper(x+leng/2, y+leng/2, leng / 2);
				pure = false;
			}
		}
	}
	if (pure)
	{
		if (temp)
		{
			blue++;
		}
		else
		{
			white++;
		}
	}
}

int main()
{
	int N,c;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> c;
			arr[i][j] = c;
		}
	}
	paper(1, 1, N);
	cout << white << endl << blue << endl;
	return 0;

}
