#include <iostream>
#include <malloc.h>
using namespace std;
int main()

{
	int n, m, k,j,o;
	int * arr;
	cin >>n >> m;
	j = 0;
	o = n;
	arr = (int *)malloc(sizeof(int)*n);
	while ( 0< n--)
	{
		cin >> k;
		arr[j]=k;
	
		j++;
	}
	j = 0;
	n = o;
	for (int i = 0; i < n - 2; i++)
	{
		for (int k = i+1; k < n - 1; k++)
		{
			for (int l = k+1; l < n; l++)
			{
				
				if (arr[i] + arr[k] + arr[l] <= m&&arr[i] + arr[k] + arr[l]>j)
				{
					j = arr[i] + arr[k] + arr[l];
				}
			}
		}
	}

	cout << j << "\n";
	return 0;
}
