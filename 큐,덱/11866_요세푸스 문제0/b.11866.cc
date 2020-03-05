#include <iostream>

using namespace std;

class Node{ //스택을 위한 
private:
	int num;
	Node* next;
	Node* prev;
public:
	Node(int a = 0, Node* linka = NULL,Node* linkb=NULL) //생성자
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
	void push(Node* node)
	{
		
		if (is_empty())
		{
			front = node;
			rear = node;
		}
		else
		{
			node->link_prev( rear);
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
		front->link_prev(NULL);
		free(node);
		len--;
	}
	void josephus(int a)
	{
		Node* node = rear;
		while (len>1)
		{
			for (int i = 1; i <= a; i++)
			{
				if (node->get_next_node() == NULL)
				{
					node = front;
				}
				else
				{
					node = node->get_next_node();
				}
			}
			Node* temp = node;
			cout << temp->get_data_num() << ", ";;
			if (front == rear)//마지막 하나 남은 노드를 위한 코드인데 출력을 위해 len>0에서len>1로 바꿔서 쓸모가 없어졌다.
			{
				free(temp);
			}
			else if (temp == rear)
			{
				node = temp->get_prev_node();
				rear = node;
				temp->get_prev_node()->link_next(NULL);
				free(temp);
				
			}
			else if (temp == front)
			{
				
				front = temp->get_next_node();
				node = rear;
				temp->get_next_node()->link_prev(NULL);
				free(temp);
			}
			else
			{
				node = temp->get_prev_node();
				temp->get_next_node()->link_prev(temp->get_prev_node());
				temp->get_prev_node()->link_next(temp->get_next_node());
				free(temp);
			}
			len--;
		}
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	linked_que q;
	int n,k, num;
	cin >> n>>k;
	num = k;
	for (int i = 1; i <= n; i++)
	{
		q.push(new Node(i));
	}
	cout << "<";
	q.josephus(num);
	cout << q.get_front()->get_data_num(); //마지막 하나 남은 노드
	cout << ">" << endl;
	return 0;
}
