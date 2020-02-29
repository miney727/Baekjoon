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
	int get_size()
	{
		Node* temp = top;
		int tem = 0;
		while (temp!=NULL)
		{
			temp = temp->get_next_node();
			tem++;
		}
		return tem;
	}
	int pop()
	{
		Node* node = top;
		top = top->get_next_node();
		return node->get_data_num();
		
	}
	int get_top_num()
	{
		if (top != NULL)
		{
			return top->get_data_num();
		}
		else
		{
			return -1;
		}
	}
};



int main()
{	
	long long hab = 0;
	int n, num;
	cin >> n;
	linked_stack s;
	for (int i = 1; i <= n; i++)
	{
		cin >> num;
		if (num)
		{
			hab += num;
			s.push(new Node(num));
		}
		else
		{
			hab -= s.pop();
		}
	}
	cout << hab << endl;
	return 0;
}
