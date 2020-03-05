#include <iostream>
#include <algorithm>

using namespace std;

class Node{ //스택을 위한 
private:
	int index;
	int num;
	Node* next;
	Node* prev;
public:
	Node(int a = 0, int b = 0, Node* linka = NULL, Node* linkb = NULL) //생성자
	{
		num = a;
		index = b;
		next = linka;
		prev = linkb;
	}
	int get_data_num()
	{
		return num;
	}
	int get_data_index()
	{
		return index;
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
	void push(Node* node)
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
	void printQ(int k)
	{
		int printn = 0;
		Node* node;
		Node* check;
		Node* temp;
		bool back;
		while (1)
		{
			back = false;
			node = front;
			check = front;
			temp = front;
			while (check != rear)
			{
				check = check->get_next_node();
				if (check->get_data_num() > node->get_data_num())
				{
					front->link_prev(NULL);
					front = temp->get_next_node();
					temp->link_prev(rear);
					temp->link_next(NULL);
					rear->link_next(temp);
					rear = temp;
					back = true;
					break;
				}
			}
			if (!back)
			{
				printn++;
				if (node->get_data_index() == k)//인덱스가 옳으면 끝
				{
					cout << printn << endl;
					return;
				}
				pop();
			}
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	linked_que q;
	int t, N, M, num;
	cin >> t;
	while (t--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			q.push(new Node(num, i));
		}
		q.printQ(M);
		while (!q.is_empty()) //
		{
			q.pop();
		}
	}

	return 0;
}
