#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	long long x, y, dis; // 거리
	int count=0;// 횟수
	
	for (int i = 0; i < T; i++)
	{
		cin >> x >> y;
		dis = y - x;
		for (long long j = 0; j < dis; j++)
		{
			if (dis <= (j + 1)*(j + 1))
			{
				if (dis > (2*j*j+2*j+1)/2)
				{
					cout << (2*j +1) << endl;
					break;
				}
				else
				{
					cout << (2 * j ) << endl;
					break;
				}
			}

		}



	}
	return 0;



}