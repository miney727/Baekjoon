#include <iostream>
using namespace std;

int is_prime(int k);
int main()
{

	int T,n,counts,countb;
	int datas[1000];
	int datab[1000];
	int F; //첫번째
	
		cin >> T;
		for (int l = 0; l < T; l++)
		{
			cin >> n;
			counts = 0, countb = 0;
			F = 0;
			for (int i =  2; i <n; i++)
			{
				if (is_prime(i) == 1)
				{
					if (i<n/2)
					{
						datas[counts] = i;
						counts++;
						
					}
					else if (i==n/2)
					{
						cout << i <<" "<< i << "\n";
						break;
					}
					else
					{
						datab[countb] = i;
						countb++;
					}	
				}
				
			}
			for (int j = counts-1; j >= 0; j--)
			{
				for (int k=0; k<countb-1; k++)
				{
					if (F == 0)
					{
						if (datas[j] + datab[k] == n)
						{
							F++;
							cout << datas[j] << " " << datab[k] << "\n";
						}
					}
				}
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
