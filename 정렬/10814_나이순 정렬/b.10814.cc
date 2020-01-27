#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,string> a, pair<int,string> b); //stable_sort 를 위한 함수
int main()
{
	int N;
	cin >> N;
	vector < pair<int, string>> v(N);
	for (int i = 0; i < N; i++) //입력
	{
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(),compare); //소트
	for (int i = 0; i < N; i++) //출력
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
	return 0;
}

bool compare(pair<int, string> a, pair<int, string> b) //나이순으로 정렬
{
	
		return a.first < b.first;
	
}
