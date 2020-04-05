#include <iostream>
using namespace std;
#define SWAP(x,y){int t; t=x;x=y;y=t;}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, num;
	long long temp;
	cin >> N;

	int *h = new int[N + 1];
	int len = 0;
	while (N--)
	{
		cin >> num;
		if (num == 0)
		{
			if (len)
			{
				cout << h[0] << "\n";
				h[0] = h[len - 1];
				len--;
				temp = 0;
				while (1)
				{
					if (temp * 2 + 2 < len && h[temp * 2 + 1] > h[temp * 2 + 2])
					{
						if (h[temp] > h[temp * 2 + 2])
						{
							SWAP(h[temp], h[temp * 2 + 2]);
							temp = temp * 2 + 2;
						}
						else
						{
							break;
						}

					}
					else
					{

						if (temp * 2 + 1 < len && h[temp] > h[temp * 2 + 1])
						{
							SWAP(h[temp], h[temp * 2 + 1]);
							temp = temp * 2 + 1;
						}
						else
						{
							break;
						}
					}



				}


			}
			else
			{
				cout << "0\n";
			}


		}
		else
		{
			h[len] = num;
			temp = len;

			while (h[(temp - 1) / 2] > h[temp])
			{
				SWAP(h[(temp - 1) / 2], h[temp]);
				temp = (temp - 1) / 2;
			}




			len++;


		}
	}
	return 0;


}
