#include <iostream>
using namespace std;

int x[101] = { 0,500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10 };
int y[65] = { 0,512, 256, 256, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32 };

int main()
{

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, a, b;
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		cout << (x[a] + y[b]) * 10000 << "\n";
	}

	return 0;
}
