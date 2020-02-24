#include <iostream>

using namespace std;

int arr[65][65];
void paper(int x,int y,int leng,int last)
{
	int temp = arr[x][y];
	bool pure = true;
	for (int i = x; i < x + leng; i++)
	{
		for (int j = y; j < y + leng; j++)
		{
			if (temp != arr[i][j]&&pure)
			{
				cout << "(";
				paper(x, y, leng / 2,1);
				paper(x, y + leng / 2, leng / 2, 3);
				paper(x+leng/2, y, leng / 2,2);
				paper(x+leng/2, y+leng/2, leng / 2,4);
				pure = false;
			}
		}
	}
	if (pure)
	{
		cout << temp;
	}
	if (last == 4) //마지막이면 괄호닫음
	{
		cout << ")";
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
			scanf("%1d", &c);
			arr[i][j] = c;
		}
	}
	paper(1, 1, N,0);
	return 0;
}
