#include <iostream>
#include <vector>
#include <algorithm>  //sort함수

using namespace std;

int main()
{
	int N, num;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[i] = num; 
	}
	sort(v.begin(), v.end());  //내장된 정렬함수 사용
	for (int i = 0; i < N; i++)
	{
		cout << v[i] << "\n";
	}
	return 0;
}
