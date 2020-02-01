/* 알고리즘 문제해결 전략책에 나온 문제다 */
#include <iostream>
#include <vector>
using namespace std;
void back(int a, int b, vector <int> v)
{
	
	if (b == 0) //다 뽑았을 시
	{
		for (int i = 0; i<v.size(); i++) //벡터의 모든 값을 출력
		{
			cout << v[i] << " ";
		}
		cout <<"\n";
		return;
	}
	int smallest = v.empty() ? 1 : v.back() + 1; //가장 작은 숫자를 고른다
	for (int next = smallest; next <= a; ++next)
	{
			v.push_back(next);
			back(a, b-1, v); //재귀
			v.pop_back();
	}
}

int main()
{
	vector <int> num;
	int N, M;
	cin >> N >> M; //입력
	back(N, M, num);
	return 0;
}
