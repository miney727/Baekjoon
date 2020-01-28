#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[26][26] = { 0, };
bool visit[26][26]= { false };
int N, M, V,a,b;
int count = 0;
vector <int> estate; //단지 
int x[4] = { -1,0,0,1 };
int y[4] = { 0, -1, 1, 0 };
bool inside(int a, int b) //배열안에 있는지
{
	return (a >= 1 && a <= N) && (b >= 1 && b <= N);
}
void DFS(int a,int b) //깊이 우선 탐색, 재귀함수
{
	visit[a][b] = true;
	::count++; //집의 수
	for (int i = 0; i < 4; i++)
	{
		if (inside(a + x[i], b + y[i]) && arr[a + x[i]][b + y[i]] == 1 && !visit[a + x[i]][b + y[i]]) //배열안&&집이존재&&방문했는가
		{
			DFS(a+x[i],b+y[i]);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%1d", &arr[i][j]); //하나씩끊어서 입력받는다
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			::count = 0;
			if (!visit[i][j] && arr[i][j] == 1) 
			{
				DFS(i, j);
			}
			if (::count != 0) //집이 존재하면 단지수를 push
			{
				estate.push_back(::count);
			}
		}
	}
	sort(estate.begin(), estate.end()); //내장 퀵정렬로 오름차순으로 정렬
	cout << estate.size() << endl;
	for (int i = 0; i < estate.size(); i++)
	{
		cout << estate[i] << endl; //출력
	}
	return 0;

}
