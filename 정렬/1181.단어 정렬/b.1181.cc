#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string a, string b); //소트 함수에 필요한 함수

int main()
{
	int N;
	cin >> N;
	string temp;
	vector<string> v(N);
	for (int i = 0; i < N; i++) //입력
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < N; i++) //출력
	{
		if (v[i] == temp) //만약 같은 단어라면 생략
		{
			continue;
		}
		cout << v[i] << "\n";
		temp = v[i];
	}

	return 0;
}

bool compare(string a, string b)
{
	if (a.length() == b.length()) //길이가 같을시 사전순
	{
		return a < b;
	}
	else
	{
		return a.length() < b.length(); 
	}
}
