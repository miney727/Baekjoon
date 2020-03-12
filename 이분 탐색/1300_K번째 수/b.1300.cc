#include <iostream>
#include <algorithm>

using namespace std;


long long N, K, num, ans;


void search()
{
	long long left = 1, right = K;
	long long  hab;
	while (left <= right)
	{
		ans = (left + right) / 2;
		hab = 0;
		for (int i = 1; i <= N; i++)
		{
			hab += min(N, ans / i);
		}
		if (K > hab)
		{
			left = ans + 1;
		}
		else
		{
			right = ans - 1;
			num = ans;
		}
	}

	cout << num << endl;
}

int main()
{
	cin >> N >> K;
	search();
	return 0;
}
