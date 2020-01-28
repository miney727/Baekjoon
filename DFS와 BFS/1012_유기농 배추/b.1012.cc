/*저번 단지번호붙이기와 아주 유사하므로 설명은 생략*/

#include <iostream>
using namespace std;

int arr[51][51] = { 0, };
bool visit[51][51]= { false };
int count = 0;
int N,M;
int x[4] = { -1,0,0,1 };
int y[4] = { 0, -1, 1, 0 };
bool inside(int a, int b)
{
	return (a >= 0 && a < N) && (b >= 0 && b < M);
}
void DFS(int a,int b)
{
	visit[a][b] = true;
	for (int i = 0; i < 4; i++)
	{
		if (inside(a + x[i], b + y[i]) && arr[a + x[i]][b + y[i]] == 1 && !visit[a + x[i]][b + y[i]])
		{
			DFS(a+x[i],b+y[i]);
		}
	}
}

int main()
{
	int T, K, x, y;

	cin >> T;
	while (T--)
	{
		cin >> N >> M >> K;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			arr[x][y] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (!visit[i][j] && arr[i][j] == 1)
				{
					DFS(i, j);
					::count++;
				}
			}
		}
		cout << ::count << endl;
		::count = 0;
		for (int i = 0; i < 51; i++)
		{
			for (int j = 0; j < 51; j++)
			{
				visit[i][j] = false;
				arr[i][j] = 0;
			}
		}
	}
	return 0;

}
