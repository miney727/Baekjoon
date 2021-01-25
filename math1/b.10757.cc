#include <iostream>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;

int num1[10002];
int num2[10002];

int main()
{
	string a, b;

	stack<int> s;

	cin >> a >> b;
	int up = 0;

	for (int i = a.length()-1; i >= 0; i--)
	{
		num1[a.length()-i-1] = a[i] - 48;
	}
	for (int i = b.length()-1; i >= 0; i--)
	{
		num2[b.length() - i - 1] = b[i] - 48;
	}
	int len = max(a.length(), b.length());

	for (int i = 0; i < len; i++)
	{
		int temp = num1[i] + num2[i]+up;
		up = temp / 10;
		s.push(temp % 10);
	}
	if (up == 1)
	{
		s.push(up);
	}


	while (!s.empty())
	{
		cout << s.top();
		s.pop();
		
	}
	cout << endl;



	return 0;



}
