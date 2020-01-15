#include <iostream>
using namespace std;
int main()

{
	int N[51][2] = {};
	int n,x,y;
	int rank;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		N[i][0] = x;
		N[i][1] = y;
	}

	for (int i = 0; i < n; i++)
	{
		rank = 1;

		for (int j = 0; j < n; j++)
		{
			if (N[i][0] < N[j][0] && N[i][1] < N[j][1])
			{
				rank++;

			}
		}
		cout << rank << endl;
	}
	

	return 0;
}
