#include <iostream>

using namespace std;

int arr[101][101] = { 0, };
bool visit[101] = {false};
int N, M, V,a,b;
int count = 0;

void DFS(int a)
{
	visit[a] = true;
	for (int i = 1; i <= N; i++)
	{
		if (arr[a][i] != 0 && !visit[i])
		{
			visit[i] = true;
			::count++; //"count" function 이 이미 std namespace에 존재하기 때문에 ::를 붙여 전역변수라는걸 확실하게 해야한다.
			DFS(i);
		}
	}


}
int main()
{
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}
	DFS(1);
	cout <<  ::count << endl;
	return 0;

}
