#include <iostream>
using namespace std;

int is_prime(int k);

int main()
{
	int M, N;
	cin >> M >> N;
	if (M <=2 )
	{
		cout << "2\n";
	}
	if (M % 2 == 0)
	{ 
		M++;
	}

	for (; M <= N; M+=2)
	{
		if (is_prime(M) == 1)
		{
			cout << M << "\n";
		}
	}
	return 0;
}


int is_prime(int k)
{
	if (k == 1)
	{
		return 0;
	}
	
	for (int j = 2; j*j < k + 1; j++)
	{
		if (k%j == 0)
		{
			return 0;
		}
	}
	return 1;

}
