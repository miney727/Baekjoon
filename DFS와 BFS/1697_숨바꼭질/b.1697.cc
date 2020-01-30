#include <iostream>
using namespace std;

class Node //큐를 위한 노드
{
public:
	int x;
	Node* next;
	Node(int a = 0, Node* link = NULL) //생성자
	{
		x = a;
		next = link;
	}
	void link(Node* link) //다음 노드와 연결
	{
		next = link;
	}
	int get_data_x()
	{
		return x;
	}
	Node* get_next_node() //다음 노드를 반환
	{
		return this->next;
	}
};

class linkedqueue //큐 연결리스트
{
	Node* front;
	Node* rear;
public:
	bool is_Empty() //비어있는지
	{
		if (front == NULL)
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
	Node* dequeue() //선출
	{
		Node * temp = front;
		front = front->get_next_node();
		return temp;
	}

};

int N, K;
bool visit[100001] = { false };
int second[100001] = { 0, }; //지난 초
bool inside(int a)
{
	return (a >= 0 && a <= 100000) ;
}
void BFS(linkedqueue q)
{
	int a,b;
	while (!q.is_Empty())
	{
		Node* k = q.dequeue();
		a = k->get_data_x();
		if (a == K) //K에 도착 했을시 답을 출력
		{
			cout << second[a]<< endl;
			return;
		}
		visit[a] = true;
		free(k);
		for (int i = 0; i < 3; i++)
		{
			switch (i)
			{
			case 0:
				b= a - 1;
				break;
			case 1:
				b= a + 1;
				break;
			case 2:
				b= a * 2;
				break;
			}
			
			if (inside(b) && !visit[b]) //배열안&&아직안갔을시
			{
				q.enqueue(new Node(b,NULL));
				visit[b] = true;
				second[b] = second[a]+1;
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	linkedqueue distance;
	distance.enqueue(new Node(N, NULL));
	BFS(distance);
	return 0;
}
