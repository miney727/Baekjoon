#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[1001][1001] = { 0, };
int main()
{
	string a, b;
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	for (int i = 1; i < a.length(); i++)
	{
		for (int j = 1; j < b.length(); j++)
		{
			if (a[i] == b[j])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}
	cout << arr[a.length()-1][b.length()-1] << endl;
	return 0;
}
