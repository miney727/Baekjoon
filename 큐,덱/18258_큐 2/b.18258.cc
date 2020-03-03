#include <iostream>
#include <string>
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
	int len; //속도 개선을 위해 len을 추가했다
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
		cout << node->get_data_num() << "\n";
		free(node);
		len--;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	linked_que s;
	string cmd;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd;
		if (cmd == "push")
		{
			cin >> num;
			s.push(new Node(num));
		}
		else if (cmd == "pop")
		{
			if (s.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{

				s.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << s.get_size() << "\n";
		}
		else if (cmd == "empty")
		{
			if (s.is_empty())
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
			if (s.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << s.get_front()->get_data_num() << "\n";
			}
		}
		else if (cmd == "back")
		{
			if (s.is_empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << s.get_rear()->get_data_num() << "\n";
			}
		}
		else
		{
			cout << "오류 발생" << endl;
		}
	}
	return 0;
}
