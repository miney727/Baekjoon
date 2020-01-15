#include <iostream>
using namespace std;

int is_prime(int k);

int main()
{
	int M, N;
	cin >> M >> N;
	int min=10000, hab=0; //최소값 과 합

	for (; M <= N; M++)
	{
		if (is_prime(M)==1)
		{
			
			if (M<min)
			{
				min = M;
			}
			hab += M;
		}
	}
	if (min == 10000)
	{
		cout << "-1" << endl;
		return 0;
	}
	cout << hab << endl << min << endl;
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
