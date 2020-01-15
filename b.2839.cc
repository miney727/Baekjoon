#include <iostream>
using namespace std;

int main()
{
	int num;
	int sum = 0;
	cin >> num;

	if (num == 4||num==7)
	{
		cout << "-1" << endl;
		return 0;
	}
	sum = num / 5;
	if (num % 5 == 0)
	{
	}
	else if (num % 5 == 1)
	{
		sum++;
	}
	else if (num % 5 == 2)
	{
		sum += 2;
	}
	else if (num % 5 == 3)
	{
		sum++;
	}
	else
	{
		sum += 2;
	}
	cout << sum << endl;

	return 0;





}
