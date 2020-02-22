#include <iostream>

using namespace std;

int gcd(int a, int b) //유클리드 호제법
{
	if (a%b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a%b);
	}
}

void ring(int a,int b)
{
	int k = gcd(a, b);
	cout << a / k << "/" << b / k << endl; //최대공약수로나눈다
}

int main()
{
	int N,num;
	int arr[100];
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	num = arr[0];
	for (int i = 1; i < N; i++)
	{
		ring(num, arr[i]);
	}
	return 0;
}
