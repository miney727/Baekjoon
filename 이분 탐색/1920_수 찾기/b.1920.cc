#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, num;
vector <int> v;

int search(int a,int leng)
{
	int indexa = 0, indexb = leng;
	int  index;
	while (1)
	{
		index = (indexa + indexb) / 2;

		if (v[index] == a)
		{
			return 1;
		}
		if (indexa == indexb-1)
		{
			return 0;
		}
		else if (v[index] > a)
		{
			indexb = index;
		}
		else
		{
			indexa = index;
		}

	}


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	int n;
	v.reserve(M);
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << search(num,M) <<" ";
	}
	return 0;
}





