#include <iostream>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	int num = 1;
	for (int i = N; i>N-K; i--)
	{
		num *= i;
		num/= (N-i+1);
	}
	cout << num << endl;
	return 0;
}
