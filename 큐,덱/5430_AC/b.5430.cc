#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>

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
		rear = rear->get_prev_node();
		free(node);
		len--;
	}
};

int n, M,T, num;
string cmd;
string number, temp;
linked_que q;
bool R,error;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = 0;
	cin >> T;
	while (T--)
	{
		R = false;
		error = false;
		cin >> cmd;
		cin >> n;
		cin >> number;
		number[number.length() - 1] = ',';
		if (number.length() > 2) //[]만 입력받으면 아무것도안한다
		{
			for (int i = 1; i < number.length(); i++)
			{
				if (number[i] == ',')
				{
					q.push_back(new Node(stoi(temp)));
					temp = "";
					continue;
				}
				temp += number[i];
			}
		}
		for (int i = 0; i < cmd.length(); i++)
		{
			if (cmd[i] == 'R') //R이 들어왔을시
			{
				R = !R;
			}
			else
			{
				if (q.is_empty()) //큐가 비어있을때 D가 입력될시 error를 출력한다
				{
					cout << "error" << endl;
					error = true;
					i = cmd.length();
					break;
				}
				if (R) //리버스상태일시 
				{
					q.pop_back();
				}
				else
				{
					q.pop_front();
				}
			}
		}
		if (!error) 
		{
			cout << "[";
			if (R) //리버스상태일시
			{
				while (q.get_size() > 1)
				{
					cout << q.get_rear()->get_data_num() << ",";
					q.pop_back();
				}
			}
			else
			{
				while (q.get_size() > 1)
				{
					cout << q.get_front()->get_data_num() << ",";
					q.pop_front();
				}
			}
			if (q.get_size() == 1)
			{
				cout << q.get_front()->get_data_num();
				q.pop_front();
			}
			cout << "]" << endl;
		}
	}

	return 0;
}
