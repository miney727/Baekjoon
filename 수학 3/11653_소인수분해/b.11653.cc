#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	vector<int> v;
	cin >> N;
	int num = 2;
	while (N != 1)
	{
		
		if (N%num == 0)
		{
			v.push_back(num);
			N /= num;
			num = 2;
		}
		else
		{
			num++;
		}
	}
	for (int i =0; i<v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}
