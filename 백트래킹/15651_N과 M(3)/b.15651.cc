/* N과 M(1)에서 중복확인만 제거하면 된다*/
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
		cout << "\n";
		return;
	}
	for (int next = 1; next <= a; ++next)
	{
			v.push_back(next);
			back(a, b - 1, v); //재귀
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
