#include <iostream>
#include <math.h>
using namespace std;
int hanoinum(int n);  //하노이 횟수
void hanoi(int n, int x, int y, int z);

int main()
{
	int N;
	cin >> N;
	cout << hanoinum(N)<< endl;
	hanoi(N, 1, 2, 3);
	return 0;

}

int hanoinum(int n)  
{
	int num = 0;
	for (int i = 0; i < n; i++)  
	{
		num = 2 * num + 1;
	}
	return num;
}
void hanoi(int n, int x, int y, int z)
{
	
	
	if (n == 1)          //기저 사례
	{
		cout << x << " " << z << "\n";
		return;
	}
	hanoi(n-1, x,z,y);                 //제일 큰 원반을 제외하고 다 가운데에 옮긴뒤
	cout << x << " " << z << "\n";    //제일 큰 원반을 옮기고
	hanoi(n - 1, y, x,z);            //나머지를 제일 큰 원반으로 옮긴다

}
