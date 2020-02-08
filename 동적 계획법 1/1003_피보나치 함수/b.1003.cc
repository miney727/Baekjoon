#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	int T,N;
	vector <pair<int, int>> v(41);
	v[0].first = 1;
	v[0].second = 0;
	v[1].first = 0;
	v[1].second = 1;
	cin >> T;
	while (T-- > 0)
	{
		cin >> N;
		
		for (int i = 2; i <= N; i++)
		{
			v[i].first = v[i - 1].first + v[i - 2].first;
			v[i].second = v[i - 1].second + v[i - 2].second;
		}
		cout << v[N].first<<" "<<v[N].second << endl;
	}
	return 0;
}
