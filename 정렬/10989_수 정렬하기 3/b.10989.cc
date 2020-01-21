#include  <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int arr[10001] = {0, };
	int N,num,i;
	cin >> N;
	for (i = 0; i < N; i++) 
	{
		scanf("%d", &num);
		arr[num]++;
	}
	for (i = 1; i < 10001; i++)
	{
		while (0<arr[i]-- )
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

