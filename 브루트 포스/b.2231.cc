#include <iostream>
#include <malloc.h>
using namespace std;
int main()

{
	int n,ans,sum,temp;
	 sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		sum = i;
		temp = i;
		while (temp != 0)
		{
			sum += temp % 10;
				temp /= 10;
		}
		if (sum == n)
		{
			cout << i << "\n";
			return 0;
		}
	}
	cout <<  "0\n";

}
