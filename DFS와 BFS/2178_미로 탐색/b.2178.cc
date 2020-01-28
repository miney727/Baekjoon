/* 최단거리를 구할때 DFS보단 BFS를 쓰는것이 좋다*/

#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Node //큐를 위한 노드
{
public:
	int x;
	int y;
	Node* next;
	Node(int a = 0,int b=0, Node* link = NULL) //생성자
	{
		x = a;
		y = b;
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
	int get_data_y()
	{
		return y;
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

int arr[101][101] = { 0, };
bool visit[101][101]= { false };
int depth[101][101] = { 0, }; //지나야 하는 최소의 칸 수
int N,M;
int x[4] = { -1,0,0,1 };
int y[4] = { 0, -1, 1, 0 };
bool inside(int a, int b)
{
	return (a >= 0 && a < N) && (b >= 0 && b < M);
}
void BFS(int a,int b)
{
	linkedqueue q;
	q.enqueue(new Node(a, b, NULL));
	visit[a][b] = true;
	depth[a][b] = 1;
	while (!q.is_Empty())
	{
		Node* k=q.dequeue();
		a = k->get_data_x();
		b = k->get_data_y();
		free(k);
		for (int i = 0; i < 4; i++)
		{
			if (inside(a + x[i], b + y[i]) && arr[a + x[i]][b + y[i]] == 1 && !visit[a + x[i]][b + y[i]])
			{
				q.enqueue(new Node(a + x[i], b + y[i]));
				visit[a + x[i]][b + y[i]] = true;
				depth[a+x[i]][b+y[i]] = depth[a][b] + 1; //한칸 지났으므로 +1을 해준다
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]); //하나씩 입력
		}
	}
	BFS(0,0);
	cout << depth[N-1][M-1] << endl; //(N,M) 위치로 이동할 때 지나야 하는 최소의 칸 수
	return 0;
}
