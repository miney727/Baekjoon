#include <iostream>
using namespace std;

int is_prime(int k);
int main()
{

	int T,count;
	count = 0;
	while (1)
	{
		count = 0;
		cin >> T;
		if (T == 0)
		{
			break;
		}
		for (int i = T+1; i <= 2 * T; i++)
		{
			if (is_prime(i)==1)
			{
				count++;
			}
		}
		cout << count << "\n";
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
