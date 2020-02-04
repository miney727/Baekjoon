/*실패 사례*/
#include <iostream>
#include <vector>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;
int s[21][21];
int N;
int minnum = 10000;
vector <int> team;
vector <bool> is_in(21, false);
void soccer(int num, int hab, int next)
{
	for (int i = num; i > 1; i--)
	{
		hab += s[team[num - 1]][team[i - 2]] + s[team[i - 2]][team[num - 1]];
	}
	if (num == N / 2)
	{
		int hab2 = 0;
		vector <int> team2;
		for (int i = 1; i <= N; i++)
		{
			if (!is_in[i])
			{
				team2.push_back(i);
			}
		}

		for (int i = 0; i < num - 1; i++)
		{
			for (int j = i + 1; j < num; j++)
			{
				hab2 += s[team2[i]][team2[j]] + s[team2[j]][team2[i]];
			}
		}

		if (abs(hab2 - hab) < minnum)
		{
			minnum = abs(hab2 - hab);

		}
		return;
	}

	for (int i = next; i <= N; i++)
	{
		if (!is_in[i])
		{
			team.push_back(i);
			is_in[i] = true;
			soccer(num + 1, hab, next + 1);
			team.pop_back();
			is_in[i] = false;
		}
	}
}
int main()
{
	int stat;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &stat);
			s[i][j] = stat;
		}
	}
	soccer(0, 0, 1);
	printf("%d\n", minnum);
	return 0;
}
