#include <iostream>
#include <algorithm>

using namespace std;

int stair[301] = { 0, };
int dp[301][2] = { 0, };

int main()
{
	int n, num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		stair[i] = num;
	}

	dp[1][0] = stair[1];
	dp[2][0] = stair[2];
	dp[2][1] = stair[2] + stair[1];
	for (int i = 3; i <= n; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			if (j == 0)
			{
				dp[i][0] =max(dp[i - 2][1] + stair[i],dp[i-2][0]+stair[i]);
			}
			else
			{
				dp[i][1] = dp[i - 1][0] + stair[i];
			}
		}

	}
	cout<<max(dp[n][0], dp[n][1]) << endl;
	return 0;
}





