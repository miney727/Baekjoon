#include <iostream>
#include <vector>
using namespace std;
int maxnum = -1000000000; //최대
int minnum = 1000000000; //최소
int N, num;
vector <int> v1(11);
vector <int> v2(4);
void op(int a, int b, vector<int> o) //a는 횟수 b는 값 c는 연산자
{
	if (a == N - 1)
	{
		if (b < minnum)
		{
			minnum = b;
		}
		if (b > maxnum)
		{
			maxnum = b;
		}
		return;
	}
	if (o[0]-- > 0) //+
	{
		op(a + 1, b + v1[a + 1], o);
		o[0]++;
	}
	if (o[1]-- > 0)//-
	{
		op(a + 1, b - v1[a + 1], o);
		o[1]++;
	}
	if (o[2]-- > 0)//*
	{
		op(a + 1, b * v1[a + 1], o);
		o[2]++;
	}
	if (o[3]-- > 0)// /
	{
		op(a + 1, b / v1[a + 1], o);
		o[3]++;
	}
}

int main()
{

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v1[i] = num; //수 입력
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> num;
		v2[i] = num; //연산자 입력
	}
	op(0, v1[0], v2);
	cout << maxnum << endl << minnum << endl;
	return 0;

}
