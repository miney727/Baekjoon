#include <iostream>
#define P 1000000007
using namespace std;

long long fac[4000001];
long long power(long long a, long long b) //a^b를 구한다
{
	long long ret = 1;
	while (b > 0)
	{
		if (b % 2 != 0)
		{
			ret *= a;
			ret %= P;
		}
		a *= a; //분할 정복
		a %= P;
		b /= 2;
	}
	return ret;
}


int main()
{
	int N, K;
	cin >> N >> K;
	fac[0] = 1;
	for (int i = 1; i <= N; i++)
	{
		fac[i] = (fac[i - 1] * i) % P;
	}
	long long num = (fac[N] * power(fac[K] * fac[N - K]%P,P-2)) %P; //페르마의 소정리
	cout << num << endl;
	return 0;
}
