#include <iostream>

using namespace std;

int main()
{
	int T, W, H, N;
	cin >> T;
	for (int i = 0; i < T;i++)
	{

	
		cin >> H >> W >> N;
		int x,y;
		if (N ==0)
		{
			 y = N;
		}
		else
		{
			 y = N%H;
		}
		if (N % H==0)
		{
			 x = N / H;
		}
		else
		{
			 x = N / H + 1;
		}
		if (y == 0)
		{
			y += H;
		}
		cout << y;
		if (1 <= x&&x <= 9)
		{
			cout << "0" << x << endl;
		}
		else
		{
			cout << x << endl;
		}


		

	
	
	
	
	
	}



	return 0;
}