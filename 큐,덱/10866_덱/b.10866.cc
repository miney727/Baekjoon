#include <iostream>
#include <string>

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
	void pop_back()
	{
		Node* node = rear;
		rear = node->get_prev_node();
		free(node);
		len--;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	linked_que q;
	int n, num;
	string cmd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push_front")
		{
			cin >> num;
			q.push_front(new Node(num));
		}
		else if (cmd == "push_back")
		{
			cin >> num;
			q.push_back(new Node(num));
		}
		else if (cmd == "pop_front")
		{
			if (q.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.get_front()->get_data_num() << endl;
				q.pop_front();
			}
		}
		else if (cmd == "pop_back")
		{
			if (q.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.get_rear()->get_data_num() << endl;
				q.pop_back();
			}
		}
		else if (cmd == "size")
		{
			cout << q.get_size() << "\n";
		}
		else if (cmd == "empty")
		{
			if (q.is_empty())
			{
				cout << "1" << "\n";
			}
			else
			{
				cout << "0" << "\n";
			}
		}
		else if (cmd == "front")
		{
			if (q.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.get_front()->get_data_num() << "\n";
			}
		}
		else if (cmd == "back")
		{
			if (q.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << q.get_rear()->get_data_num() << "\n";
			}
		}
		else
		{
			cout << "오류 발생" << endl;
		}
	}
	return 0;
}
