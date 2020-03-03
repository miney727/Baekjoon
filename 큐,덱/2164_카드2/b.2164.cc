#include <iostream>

using namespace std;

class Node{ //스택을 위한 
private:
	int num;
	Node* next;
public:
	Node(int a = 0, Node* link = NULL) //생성자
	{
		num = a;
		next = link;
	}
	int get_data_num()
	{
		return num;
	}
	void set_num(int x)
	{
		num = x;
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
	void push(Node* node)
	{
		
		if (is_empty())
		{
			front = node;
			rear = node;
		}
		else
		{
			rear->link(node);
			rear = node;
		}
		len++;
	}
	int get_size()
	{
		return len;
	}
	void pop()
	{
		Node* node = front;
		front = node->get_next_node();
		free(node);
		len--;
	}
	void change()
	{
		Node* node = front;
		rear->link(node);
		front = node->get_next_node();
		node->link(NULL);
		rear = node;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	linked_que q;
	int n, num;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		q.push(new Node(i));
	}
	while (q.get_size()!=1)
	{
		q.pop();
		q.change();
	}
	cout << q.get_front()->get_data_num() << endl;
	return 0;
}
