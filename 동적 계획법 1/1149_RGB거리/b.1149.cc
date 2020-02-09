#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][3];
int hab[1001][3] = { 0, };
int N;
void color()
{
	hab[0][0] = arr[0][0]; 
	hab[0][1] = arr[0][1];
	hab[0][2] = arr[0][2];
	if (N == 2) //첫 집(1 번째)과 마지막 집(2 번째)은 이웃이 아니므로 값은 색으로 칠할 수 있다
	{
		hab[1][0] = arr[1][0] + min(min(arr[0][0], arr[0][1]), arr[0][2]);
		hab[1][1] = arr[1][1] + min(min(arr[0][0], arr[0][1]), arr[0][2]);
		hab[1][2] = arr[1][2] + min(min(arr[0][0], arr[0][1]), arr[0][2]);
		return;
	}
	for (int i = 1; i < N; i++)
	{
		hab[i][0] = arr[i][0] + min(hab[i - 1][1], hab[i - 1][2]);
		hab[i][1] = arr[i][1] + min(hab[i - 1][0], hab[i - 1][2]);
		hab[i][2] = arr[i][2] + min(hab[i - 1][0], hab[i - 1][1]);
	}
}
int main()
{
	int R, G, B;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> R >> G >> B; //입력
		arr[i][0] = R;
		arr[i][1] = G;
		arr[i][2] = B;
	}
	color();
	cout << min(min(hab[N - 1][0], hab[N - 1][1]), hab[N - 1][2]) << endl; //세가지 값 중 최솟값을 출력
	return 0;
}
