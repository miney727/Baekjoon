#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	int T, n;
	vector < pair<int, string>> v;
	bool flag;
	string a, b;
	cin >> T;
	while (T--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			flag = false;
			cin >> a >> b;
			for (int j = 0; j < v.size(); j++)
			{
				if (b == v[j].second) //이미 존재하면
				{
					v[j].first++;
					flag = true;
				}
			}
			if (!flag) //존재 안할시 새로 생성
			{
				v.push_back(make_pair(1, b));
			}
		}
		n = 1;
		for (int i = 0; i < v.size(); i++)
		{
			n *= (v[i].first + 1); //입을지 안입을지
		}
		cout << n-1 << endl; //알몸인 경우를 제외
		v.clear();
	}
	return 0;

}
