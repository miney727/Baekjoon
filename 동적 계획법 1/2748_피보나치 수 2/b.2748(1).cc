/*벡터를 이용한 동적 계획법*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <long long> v(n+1);
	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v[n] << endl;
	return 0;
}
