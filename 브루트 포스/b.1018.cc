
#include <iostream>
using namespace std;

int paint(int a, int b); //몇칸을 색칠해야되는지 반환하는 함수
char chess[51][51]; //체스판
int main()
{
	int N, M, count;
	int min = 64;   //최솟값
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> chess[i][j];

		}
	}
	for (int i = 7; i <N; i++)    //체스판을 8X8칸으로 한번씩 잘라본다
	{
		for (int j = 7; j < M; j++)
		{
			if (paint(i, j) < min)  //최솟값 비교
			{
				min = paint(i, j);
			}
		}
	}
	cout << min << endl;
	return 0;
}

int paint(int a, int b)
{
	int count1 = 0;
	int count2 = 0;
	char WB[3] = { 'W', 'B' }; //비교할 배열
	for (int i = a - 7; i <a + 1; i++)
	{
		for (int j = b - 7; j < b + 1; j++)
		{
			if (WB[(i + j) % 2] != chess[i][j])   //번갈아가면서 비교한다
			{
				count1++;
			}
		}
	}
	for (int i = a - 7; i <a + 1; i++)
	{
		for (int j = b - 7; j < b + 1; j++)
		{
			if (WB[(i + j+1) % 2] != chess[i][j]) //바꿔서 한번 더
			{
				count2++;
			}
		}
	}
	
	if (count1 < count2)   //그중 작은걸 봔환
	{
		return count1;
	}

	return count2;

	}
