#include <iostream>

using namespace std;

long long power(long long a, long long b) //a^b를 구하는 함수
{
	long long ret = 1;
	while (b > 0)
	{
		if (b % 2!=0)
		{
			ret *= a;
			ret %= 10007;
		}
		a *= a;
		a %= 10007;
		b /= 2;
	}
	return ret;
}

int main()
{
	int N, K;
	long long fac[1001]; //팩토리얼 동적 계획
	cin >> N >> K;
	fac[0] = 1;
	fac[1]= 1;
	for (int i = 1; i <= N; i++)
	{
		fac[i] = (fac[i - 1] * i) % 10007;
	}
  //10007은 소수이므로 페르마의 소정리를 활용하여 (N!/K!*(N-K)!)%10007=N!%10007*(K!(N-K)!)^10005%10007이다.
	long long num = (fac[N] * power(fac[K]*fac[N-K],10005)) % 10007; 
	cout << num<< endl;
	return 0;
}
