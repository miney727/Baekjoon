#include <iostream>

using namespace std;

int main()
{
	int a, b, c,d;
	cin >> a >> b >> c;
	if (c>b){
		d = a / (c - b);
		d++;
		cout << d << endl;
	}
	else
	{
		cout << "-1" << endl;
	}
	return 0;



}