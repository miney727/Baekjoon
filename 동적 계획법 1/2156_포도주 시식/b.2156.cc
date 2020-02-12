#include <iostream>
#include <algorithm>
using namespace std;
int wine[10000];
int hab[10000];
void maxwine(int a)
{
	hab[0] = wine[0];
	if (a == 1)
	{
		cout << hab[0] << endl;
		return ;
	}
	hab[1] = wine[1] + hab[0];
	if (a == 2)
	{
		cout << hab[1] << endl;
		return;
	}
	for (int i = 2; i <= a-1; i++)
	{
		hab[i] = max(hab[i], wine[i] + hab[i-2]); 
		hab[i] = max(hab[i], wine[i]+wine[i-1] + hab[i-3]);
		hab[i] = max(hab[i], hab[i-1]);
	}
	cout << hab[a-1] << endl;
}
int main()
{
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		wine[i] = num;
	}
	maxwine(n);
	return 0;
}
