#include <iostream>

using namespace std;

int main()

{
	int A=0, B=0, V=0;
	cin >> A>> B>> V;
	int c = 0;
	int snail=0, day=0;
	day = (V-B) / (A - B);
	if ((V - B) % (A - B)!=0)
	{
		cout << day + 1 << endl;
		return 0;
	}
	cout << day << endl;
	return 0;

}