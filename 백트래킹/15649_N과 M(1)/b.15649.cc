#include <iostream>
#include <vector>
using namespace std;
void back(int a, int b, vector <int> v)
{
	bool flag = false; //중복값을 확인할 플래그
	if (b == 0) //다 뽑았을 시
	{
		for (int i = 0; i<v.size(); i++) //벡터의 모든 값을 출력
		{
			cout << v[i] << " ";
		}
		cout <<"\n";
		return;
	}
	for (int next = 1; next <= a; ++next)
	{
		for (int i = 0; i < v.size(); i++) //중복 확인
		{
			if (v[i] == next)
			{
				flag = true;
			}
		}
		if (!flag) //중복이 없을 시
		{
			v.push_back(next);
			back(a, b-1, v); //재귀
			v.pop_back();
		}
		flag = false;
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
