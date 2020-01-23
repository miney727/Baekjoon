#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
	int N, num;
	int count = 0;; //최빈값
	int min = 4001;   //최소
	int max = -4001; //최대
	double sum = 0; //합
	cin >> N;
	vector<int> v(8001);
	vector<int> v2(0); //최빈값용
	for (int i = 0; i < N; i++)  //입력받으면서 범위를 구할 최대값,최솟값을 구한다
	{
		cin >> num;
		v[num+4000]++;
		sum += num;
		if (num > max)
		{
			max = num;
		}
		if (num < min)
		{
			min = num;
		}
	}
	cout << round(sum / N) << "\n";  //평균 소숫점 반올림
	

	for (int i = 0; i < 8001; i++) //중앙값
	{
		if (v[i] > 0)
		{
			N -= v[i] * 2;
			if (N < 0)
			{
				cout << i - 4000 << endl;
				break;
			}
		}

	}

	for (int i = 8000; i >= 0; i--)
	{
		if (v[i]>count)
		{
			v2.clear();
			count = v[i];
		}
		if (v[i] == count)
		{
			v2.push_back(i);
		}
	}

	if (v2.size() < 2)
	{
		cout << v2[0]-4000<<endl;
	}
	else
	{
		cout << v2[v2.size() - 2]-4000 << endl;
	}
	
	cout << max-min<< "\n"; //범위
	return 0;
}
