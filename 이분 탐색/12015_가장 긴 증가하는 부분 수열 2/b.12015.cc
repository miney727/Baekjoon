#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000000];
int N, M, num, ans,maxleng,prevnum;
vector <int> v;



void LIS()
{
	v.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		int left = 0, right = v.size();
		if (arr[i] > v[v.size() - 1])
		{
			v.push_back(arr[i]);
		}
		else
		{
			while (left < right) //lower bound
			{
				ans = (left + right) / 2;
				if (arr[i] <= v[ans])
				{
					right = ans;
				}
				else
				{
					left = ans + 1;
				}
			}
			v[right] = arr[i];
		}
		
	}
	cout << v.size() << endl;
}

int main()
{
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	v.reserve(N);
	LIS();
	return 0;
	
}
