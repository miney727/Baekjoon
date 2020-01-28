#include <iostream>
using namespace std;
void DFS(int a);
void BFS(int a);
class Node
{
private:
	int data;
	Node* next;
public:
	
	Node(int a = 0, Node* link = NULL) //생성자
	{
		data = a;
		next = link;
	}
	int get_data() //data 를 리턴
	{
		return data;
	}
	void say_data() //data를 출력
	{
		cout << data << " ";
	}
	void link(Node* link) //다음 노드와 연결
	{
		next = link; 
	}
	Node* get_next_node() //다음 노드를 반환
	{
		return this->next;
	}
};


class linkedqueue{
	Node* front;
	Node* rear;
public:
	bool is_Empty() //비어있는지
	{
		if (front==NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	linkedqueue(Node* fnode = NULL, Node* rnode = NULL) //생성자
	{
		front = fnode;
		rear = rnode;
	}
	void enqueue(Node* node) //선입
	{
		if (is_Empty()) //비어있을시
		{
			front = rear = node;
		}
		else
		{
			rear->link(node);
			rear = node;
		}
	}
	int dequeue() //선출
	{
		int tem;
		Node * temp = front;
		tem = temp->get_data();
		front = front->get_next_node();
		temp->say_data();
			free(temp);
			return tem;
	}


};

int N, M, V, a, b;
int arr[1001][1001] = { 0, };
int visit1[1001] = { 0, };
int visit2[1001] = { 0, };


int main()
{
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] =arr[b][a] = 1;
	}
	DFS(V);
	cout << endl;
	BFS(V);
	return 0;

}

void DFS(int a)
{
	
	cout << a << " ";
	visit1[a] = 1;
	for (int i = 1; i <=  N; i++)
	{
		if (visit1[i]!=1&&arr[a][i]==1)
		{
			DFS(i);
		}
	}
}
void BFS(int a)
{

	linkedqueue q;
	q.enqueue(new Node(a, NULL));
	visit2[a] = 1;
	while (!q.is_Empty())
	{
		a=q.dequeue();
		for (int i = 0; i <= N; i++)
		{
			if (arr[a][i] == 1 && visit2[i] != 1)
			{
				q.enqueue(new Node(i, NULL));
				visit2[i] = 1;
			}
		}
	}

}
