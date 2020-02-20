#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <pair<int, int>> arr;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
	{
		return a.first < b.first; //시작하자마자 끝나는 경우
	}
	else
	{
		return a.second < b.second;
	}
}

int main()
{
	int n,a, b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a, b));
	}
	sort(arr.begin(), arr.end(),cmp);
	int t = 0;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (t <= arr[i].second&&t<= arr[i].first)
		{
			t = arr[i].second;
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
