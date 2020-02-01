#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int arr[10][10] = { 0, };
int count = 0;
bool flag; //하나만 출력
vector <pair<int, int>> v;
bool possible1(int a, int b,int c) //행,열 확인
{
	for (int i = 1; i <= 9; i++)
	{
		if (arr[a][i] == c)
		{
			return false;
		}
		if (arr[i][b] == c)
		{
			return false;
		}
	}
	return true;
}
bool possible2(int a, int b, int c)//3x3 확인
{
	for (int i = ((a - 1) / 3)*3+1; i < ((a - 1) / 3)*3 + 4; i++)
	{
		for (int j = ((b - 1)/3)*3+1; j < ((b - 1) / 3)*3 + 4; j++)
		{
			if (arr[i][j] == c)
			{
				return false;
			}
		}
	}
	return true;
}
void sudoku(int n)
{
	if (!flag)
	{
		int x, y;
		if (n == ::count)
		{
			for (int i = 1; i <= 9; i++) //출력
			{
				for (int j = 1; j <= 9; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}
			flag = true; //하나만 출력
			return;
		}
		for (int i = 1; i <= 9; ++i)
		{
			x = v[n].first;
			y = v[n].second;
			if (possible1(x, y, i) && possible2(x, y, i))
			{
				arr[x][y] = i;
				sudoku(n + 1);
				arr[x][y] = 0; //백트래킹
			}
		}
	}
}
int main()
{
	int x,y,n;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> n; //입력
			arr[i][j] = n;
			if (n == 0)
			{
				::count++; //빈칸의 수
				v.push_back(make_pair(i, j));
			}
		}
	}
	sudoku(0);
	return 0;
}
