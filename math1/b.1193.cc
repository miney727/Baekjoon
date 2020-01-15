#include <iostream>

using namespace std;

int main()
{

	int a;
	int b = 0, c = 0;
	cin >> a;
	for (a = a; a > b;c++)
	{
		b += c;
	}
	if (c % 2 == 0)  //큰거부터 시작
	{
		cout <<-a+b+1<<"/"<<a-b+c-1<< endl;
	}
	else    //작은거부터 시작
	{
		cout << a - b + c - 1 << "/" << -a + b + 1 << endl;
	}
}
