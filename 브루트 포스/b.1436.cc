#include <iostream>
using namespace std;

int main()
{
	int N,temp;
	int t = 1;
	int count = 0;
	cin >> N;
	while (0 < N)
	{
		count = 0;
		temp = t;
		while (temp != 0)
		{
			if (temp%10==6)  //6이 들어가는지
			{
				count++;
			}
			else            //연속인지 확인
			{
				count = 0;
			}
			if (count > 2) //6이 3번이상 연속이 되는
			{
				N--;
				break;
			}
			temp /= 10;
		}
		t++;
	}
	cout << t-1 << endl;
	return 0;

}

