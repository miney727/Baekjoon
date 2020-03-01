#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Node{ //스택을 위한 
private:
	char num;
	Node* next;
public:
	Node(char a = '0', Node* link = NULL) //생성자
	{
		num = a;
		next = link;
	}
	char get_data_num()
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
	Node* returntop()
	{
		return top;
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
		while (temp != NULL)
		{
			temp = temp->get_next_node();
			tem++;
		}
		return tem;
	}
	void pop()
	{
		Node* node = top;
		top = top->get_next_node();
	}
};
int main()
{
	linked_stack s;
	int temp;
	bool balance;
	char bracket[101];
	while (11037)
	{
		balance = true;
		cin.getline(bracket, 101);
		temp = strlen(bracket);
		if (temp == 1 && bracket[0] == '.')
		{
			return 0;
		}
		for (int j = 0; j < temp; j++)
		{
			if (bracket[j] == '(')
			{
				s.push(new Node('('));
			}
			else if (bracket[j] == ')')
			{
				if (!s.is_empty()&&s.returntop()->get_data_num() == '(')
				{
					s.pop();
				}
				else
				{
					balance = false;
				}
			}
			else if (bracket[j] == '[')
			{
				s.push(new Node('['));
			}
			else if (bracket[j] == ']')
			{
				if (!s.is_empty() && s.returntop()->get_data_num() == '[')
				{
					s.pop();
				}
				else
				{
					balance = false;
				}
			}
			bracket[j] = '\0';
		}
		while (!s.is_empty())
		{
			s.pop();
			balance = false;
		}

		if (balance)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}

	}
	return 0;
}
