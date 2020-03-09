#include <iostream> //테스트케이스가 추가되니 오답처리가 되었다.
#include <algorithm>
using namespace std;
int arr[305] = { 0, };
int hab[305] = { 0, };

void stair(int n)
{
//시작에서 시작할시
	hab[2] = max(hab[2], arr[2]); //바로 두칸
	hab[3] = max(hab[3], arr[3] + arr[1]);//한칸 뒤 두칸
	hab[4] = max(hab[4], arr[4] + arr[1] + arr[2]);//한칸 한칸 뒤 두칸
	for (int i = 1; i <= n; i++)
	{
		hab[i+2] =max(hab[i+2], arr[i+2] + hab[i]); //바로 두칸
		hab[i + 3] = max(hab[i+3],arr[i + 3]+arr[i+1] + hab[i]);//한칸 뒤 두칸
	}
	hab[n] = max(hab[n], hab[n - 1] + arr[n]); //바로 전칸에하 한칸 올라가기
	cout << hab[n] << endl;
}
int main()
{
	int N, num;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	stair(N);
	return 0;
}
