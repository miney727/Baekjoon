#include <iostream>
#include <algorithm>

using namespace std;

int count_five(long long x)
{
	long long count = 0;
	for (long long i = 5; i <= x; i *= 5)
	{
		count += x / i;
	}
	return count;
}

int count_two(long long x)
{
	long long count = 0;
	for (long long i = 2; i <= x; i *= 2)
	{
		count += x / i;
	}
	return count;
}

int main()
{
	long long n,m,  two, five;
	cin >> n >> m;
	two = count_two(n);
	five = count_five(n);
	two -= count_two(n - m);
	five -= count_five(n - m);
	two -= count_two(m);
	five -= count_five(m);
	cout << min(two, five) << endl;
	return 0;
}
