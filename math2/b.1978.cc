#include <iostream>
using namespace std;


int is_prime(int k);
int main()

{
	int T, a;
	int c = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a;
		if (is_prime(a)==1)
		{
			c++;
		}
	}

	cout << c << endl;
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
