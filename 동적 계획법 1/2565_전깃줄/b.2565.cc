#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
vector <pair<int, int>> arr;
int num[501] = { 0, };
void elec()
{
	int maxnum;
	for (int i = 0; i < n; i++)
	{
		maxnum = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i].second > arr[j].second&&maxnum<num[j])
			{
				maxnum = num[j];
			}
		}
		num[i] += maxnum+1;
	}
	for (int i = 0; i < n; i++)
	{
		if (maxnum < num[i])
		{
			maxnum = num[i];
		}
	}
	cout <<n-maxnum << endl;
}
int main()
{
	int a,b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back( make_pair(a, b));
	}
	sort(arr.begin(), arr.end());
	elec();
	return 0;
}
