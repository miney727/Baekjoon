#include <iostream>
#include <algorithm>
using namespace std;

int backpack[100001] = { 0, };
pair<int, int> mat[101];

int main()
{
	int n, k, w, v;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> w >> v;
		mat[i] = make_pair(w, v);
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = k; j - mat[i].first >= 0; j--) //중복으로 들어갈수있으므로 끝부터
		{
			backpack[j] = max(backpack[j], backpack[j - mat[i].first] + mat[i].second);
		}
	}
	cout << backpack[k] << endl;

	return 0;
}
