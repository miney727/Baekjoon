#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T,N;
	cin >> T;
	while (T-- > 0)
	{
		cin >> N;
		vector <long long> v(N+2);
		v[0] = 1;
		v[1] = 1;
		v[2] = 1;
		for (int i = 3; i < N; i++)
		{
			v[i] = v[i - 2] + v[i - 3];
		}
		cout << v[N - 1] << endl;
	}
	return 0;
}
