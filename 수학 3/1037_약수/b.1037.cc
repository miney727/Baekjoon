#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N,num;
	cin >> N;
	int arr[50];
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	sort(arr, arr+N);
	if (N % 2 == 0)
	{
		cout <<arr[0]*arr[N-1] << endl;
	}
	else
	{
		cout << arr[N/2]*arr[N/2] << endl;
	}
	return 0;
}
