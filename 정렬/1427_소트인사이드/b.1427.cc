#include <iostream>
using namespace std;

int main()
{
	int N;
	int arr[10]{0, };
	cin >> N;
	while (N > 0)
	{
		arr[N % 10]++;
		N /= 10;
	}
	for (int i = 9; i >= 0; i--)
	{
		while (0 < arr[i]--)
		{
			cout << i;
		}
	}
	cout << endl;
	return 0;
}
