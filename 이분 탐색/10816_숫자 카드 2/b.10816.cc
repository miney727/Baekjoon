#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int M, num;
int v[500000];


int findL(int s, int e, int n)
{

	int m;
	while (e - s > 0)
	{
		m = (s + e) / 2;
		if (v[m] != n)
		{
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}
	return e ;

}
int findR(int s, int e, int n)
{
	int m;
	while (e - s > 0)
	{
		m = (s + e) / 2;
		if (v[m] <= n)
		{
			s = m + 1;
		}
		else
		{
			e = m;
		}
	}
	return e ;

}
int search(int a)
{
	int indexa = 0, indexb = M - 1;
	int  index;
	while (indexa <= indexb)
	{
		index = (indexa + indexb) / 2;

		if (v[index] == a)
		{
			return  findR(index, indexb+1, a) - findL(indexa, index, a) ;
		}
		else if (v[index] > a)
		{
			indexb = index-1;
		}
		else
		{
			indexa = index+1;
		}

	}
	return 0;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> M;
	int n;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		v[i] = num;
	}
	sort(v, v + M);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cout << search(num) <<" ";
	}
	cout << "\n";
	return 0;
}



