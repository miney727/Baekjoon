#include <iostream>
#include <vector>
using namespace std;


void quick_sort(vector<int>& l, int left, int right) //call by reference로 벡터의 값을 바꾼다
{
	if (left >= right)
	{
		return;
	}
	int pivot, temp, low, high;
	low = left + 1;
	high = right;
	pivot = l[left];
	while (low <= high)
	{
		while (low <= right&&l[low] <= pivot) //pivot보다 큰 로우를 찾는다
		{
			low++;
		}
		while (high > left &&l[high] >= pivot) //pivot보다 작은 하이를 찾는다
		{
			high--;
		}
		if (low > high)  //엇갈렸을시 pivot이랑 하이를 교환 
		{
			temp = l[left];
			l[left] = l[high];
			l[high] = temp;
		}
		else  //로우와 하이를 교환
		{
			temp = l[low];
			l[low] = l[high];
			l[high] = temp;
		}

	}
	//엇갈렸을시 분할하여 재귀 실행
	quick_sort(l, left, high - 1);
	quick_sort(l, high + 1, right);


}
int main()
{
	int N;
	cin >> N;
	vector < int> v(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	quick_sort(v, 0, N - 1);
	for (int i = 0; i < N; i++)
	{
		cout << v[i]<<"\n";
	}
	return 0;
}
