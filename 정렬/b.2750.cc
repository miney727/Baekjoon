#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N,num, temp;
	cin >>N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) //
	{
		cin >> num;
		v[i] = num;
	}
	for (int j = 0; j < N - 1; j++)        //버블소트
  {
		for (int i = 0; i < N - 1; i++)
		{

			if (v[i] > v[i + 1])
			{
				temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)      //출력
	{

		cout << v[i] << endl;
	}


	return 0;
}
