#include <iostream>
#include <algorithm>

using namespace std;

class Node{ //스택을 위한 
private:
	int num;
	Node* next;
	Node* prev;
public:
	Node(int a = 0, Node* linka = NULL, Node* linkb = NULL) //생성자
	{
		num = a;
		next = linka;
		prev = linkb;
	}
	int get_data_num()
	{
		return num;
	}
	void set_num(int x)
	{
		num = x;
	}
	void link_next(Node* link)
	{
		next = link;
	}
	void link_prev(Node* link)
	{
		prev = link;
	}
	Node* get_next_node() //다음 노드를 반환
	{
		return next;
	}
	Node* get_prev_node()
	{
		return prev;
	}
};
class linked_que //연결리스트 스택
{
private:
	Node* front;
	Node* rear;
	int len;
public:
	linked_que(Node* linka = NULL, Node* linkb = NULL, int l = 0)
	{
		front = linka;
		rear = linkb;
		len = l;
	}
	Node* get_front()
	{
		return front;
	}
	Node* get_rear()
	{
		return rear;
	}
	bool is_empty()
	{
		return len == 0;
	}
	void push_back(Node* node)
	{

		if (is_empty())
		{
			front = node;
			rear = node;
		}
		else
		{
			node->link_prev(rear);
			rear->link_next(node);
			rear = node;
		}
		len++;
	}
	void push_front(Node* node)
	{
		if (is_empty())
		{
			front = node;
			rear = node;
		}
		else
		{
			node->link_next(front);
			front->link_prev(node);
			front = node;
		}
		len++;
	}
	int get_size()
	{
		return len;
	}
	void pop_front()
	{
		Node* node = front;
		front = node->get_next_node();
		free(node);
		len--;
	}
	void rotate1()
	{
		Node* temp = front;
		front = front->get_next_node();
		front->link_prev(NULL);
		temp->link_prev(rear);
		temp->link_next(NULL);
		rear->link_next(temp);
		rear = temp;
	}
	void rotate2()
	{
		Node* temp = rear;
		rear = rear->get_prev_node();
		rear->link_next(NULL);
		temp->link_next(front);
		temp->link_prev(NULL);
		front->link_prev(temp);
		front = temp;
	}
};

int minnum = 2500;

int N, M, num;
int arr[51];
int r;

linked_que q;
void tes( int n,int ans)
{
	if (n == M)
	{
		if (ans < minnum)
		{
			minnum = ans;
		}
		return;
	}
	int temp = 0;
	Node* node = q.get_front();
	while(node->get_data_num() != arr[n])
	{
		node = node->get_next_node();
		temp++;
	}
	if (temp < q.get_size() -temp)
	{
		while (temp)
		{
			q.rotate1();
			ans++;
			temp--;
		}
		q.pop_front();
	}
	else
	{
		while (q.get_size() - temp)
		{
			q.rotate2();
			ans++;
			temp++;
		}
		q.pop_front();
	}
	tes(n + 1, ans);
	
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		q.push_back(new Node(i));
	}
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		arr[i] = num;
	}
	tes(0,0);
	cout <<minnum << endl;
	return 0;
}
