#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int T, a, b, temp;
	char bracket[51];
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		a = 0, b = 0;
		cin >> bracket;
		temp = strlen(bracket);
		for (int j = 0; j < temp; j++)
		{
			if (bracket[j] == '(')
			{
				a++;
			}
			else
			{
				b++;
				if (b > a) //(앞에)가 오면
				{
					j = temp;
				}
			}
			bracket[j] = '\0'; //초기화
		}
		if (a == b)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
