#include <iostream>

using namespace std;

class Node
{ 
private:
	long long height;
	long long index;
	Node* next;
public:
	Node(long long a = 0, long long b = 0, Node* link = NULL) //생성자
	{
		height = a;
		index = b;
		next = link;
	}
	long long get_data_height()
	{
		return height;
	}
	long long get_data_index()
	{
		return index;
	}
	void link(Node* link)
	{
		next = link;
	}
	Node* get_next_node() //다음 노드를 반환
	{
		return this->next;
	}
};
class linked_stack //연결리스트 스택
{
private:
	Node* top;
public:
	linked_stack(Node* link = NULL)
	{
		top = link;
	}
	bool is_empty()
	{
		if (top == NULL)
		{
			return true;
		}
		return false;
	}
	void push(Node* node)
	{
		if (is_empty())
		{
			top = node;
		}
		else
		{
			node->link(top);
			top = node;
		}
	}
	Node* pop()
	{
		Node* node = top;
		top = top->get_next_node();
		return node;
	}
	long long top_height()
	{
		return top->get_data_height();
	}
	long long top_index()
	{
		return top->get_data_index();
	}
};


int arr[100004];

int main()
{	
	
	long long n, num;
	long long area;
	linked_stack s;
	while (11037)
	{
		area = 0;
		cin >> n;
		if (n == 0)
		{
			return 0;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> num;
			arr[i] = num;
		}
		for (int i = 0; i < n; i++)
		{
			int index = i;
			while (!s.is_empty() && s.top_height() >= arr[i]) //스택이 비어있지않음&&top보다 높이가 작으면
			{
				if (area < (i - s.top_index())*s.top_height()) //넓이 비교
				{
					area = (i - s.top_index())*s.top_height();
				}
				index = s.top_index();
				s.pop();
			}
			s.push(new Node(arr[i], index));

		}
		while (!s.is_empty()) //마지막 계산
		{
			if (area < (n - s.top_index())*s.top_height()) //
			{
				area = (n - s.top_index())*s.top_height();
			}
			s.pop();
		}
		cout <<area << endl;
	}
}
