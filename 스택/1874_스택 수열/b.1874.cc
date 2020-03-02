#include <iostream>
#include <vector>

#pragma warning (disable:4996)
using namespace std;

#include <iostream>
#include <string>
#include <string.h>
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
	int n,num;
	int indexa = 1;
	int indexv = 0;
	bool poss = true;
	linked_stack s;
	cin >> n;
	vector <int> v(n);
	vector <char> c;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		v[i] = num;
	}
	while (indexv != n&&poss)
	{
		if (s.is_empty())
		{
			s.push(new Node(indexa));
			c.push_back('+');
			indexa++;
		}
		if (v[indexv] >= indexa)
		{
			while (s.returntop()->get_data_num() != v[indexv] && poss)
			{
				s.push(new Node(indexa));
				c.push_back('+');
				if (indexa > n)
				{
					poss = false;
				}
				indexa++;
			}
			s.pop();
			c.push_back('-');
			indexv++;
		}
		else
		{
			if (s.returntop()->get_data_num() == v[indexv])
			{
				s.pop();
				c.push_back('-');
				indexv++;
			}
			else
			{
				poss = false;
			}
		}
	}

	if (poss)
	{
		while (!s.is_empty() && poss)
		{
			s.pop();
			c.push_back('-');
		}
		for (int i = 0; i < c.size(); i++)
		{
			printf("%c\n", c[i]);
		}
	}
	else
	{
		printf("NO\n");

	}

	return 0;
}
