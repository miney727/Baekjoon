#include <iostream>
using namespace std;


int factorial(int n);

int main()
{
	int n;
	cin >> n;

	cout << factorial(n) << endl;
}

int factorial(int n)
{
	if (n < 2)
	{
		return  1;
	}

	return n*factorial(n - 1);

}
