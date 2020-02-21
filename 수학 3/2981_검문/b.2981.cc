#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a,int b) //유클리드 호제법
{
	if (a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b,a%b);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	int arr[100];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;	
	}
	sort(arr, arr + N); //정렬
	num = arr[1] - arr[0];
	for (int i = 2; i < N; i++)
	{
		num = gcd(num, arr[i] - arr[i - 1]);//최대공약수
	}
	for (int i = 2; i <= num/2; i++)//최대공약수의 약수 출력
	{
		if (num%i == 0)
		{
			cout << i << " ";
		}
	}
	cout << num << endl;

	return 0;
}

