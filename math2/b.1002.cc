#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int T,temp;

	int x1, y1, r1, x2, y2, r2;
	int flag = 0;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		flag = 0;
		if (x1 == x2&&y1 == y2)                //두점이 일치할때
		{
			if (r1 == r2)						//반지름까지
			{
				cout << "-1\n";
				flag++;
			}
			else {
				cout << "0\n";
				flag++;
			}
		}
		if (flag == 0){
			if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < r1*r1 || (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < r2*r2) // 원안에 원있을때
			{
				if (r1 > r2)
				{
					temp = r1;
					r1 = r2;
					r2 = temp;

				}
				if (y2 > y1)
				{
					temp = y2;
					y2 = y1;
					y1 = temp;

				}
				if (x2 > x1)
				{
					temp = x1;
					x1 = x2;
					x2 = temp;

				}
				if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + 2 * r1*sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) + r1*r1 == r2*r2)
				{
					cout << "1\n";
					flag++;
				}
				else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + 2 * r1*sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) + r1*r1 > r2*r2)
				{
					cout << "2\n";
					flag++;
				}
				else
				{
					cout << "0\n";
					flag++;
				}

			}
		}
		if (flag == 0)  //그 외
		{
			if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) < (r1 + r2)*(r1 + r2))
			{
				cout << "2\n";
			}
			else if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) == (r1 + r2)*(r1 + r2))
			{
				cout << "1\n";
			}
			else
			{
				cout << "0\n";
			}
		}





	}


	return 0;
}
