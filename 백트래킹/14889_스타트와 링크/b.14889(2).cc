/*성공 사례*/
#include <iostream>
#include <vector>
#include <cmath>
#pragma warning (disable:4996)
using namespace std;
int s[21][21];
int N;
int minnum = 10000;
bool is_in[21];

void soccer(int num,  int next)
{
	
	if (num == N / 2)
	{
		int hab = 0;
		int hab2 = 0;
		for (int i = 0; i <= N-1; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				if (is_in[i] && is_in[j])
				{
					hab += s[i][j] + s[j][i];
				}
				if (!is_in[i] && !is_in[j])
				{
					hab2 += s[i][j]+ s[j][i];
				}
			}
		}
		if (abs(hab2 - hab) < minnum)
		{
			minnum = abs(hab2 - hab);

		}
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!is_in[i]&&i>next) //이 부분의 추가로 시간효율성이 엄청 올라갔다.
		{
			is_in[i] = true;
			soccer(num + 1, i);
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
	soccer(0, 0);
	cout << minnum << endl;
	return 0;
}
