#include <iostream>
using namespace std;

class Node //큐를 위한 노드
{
public:
	int x;
	int y;
	Node* next;
	Node(int a = 0, int b = 0, Node* link = NULL) //생성자
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

int arr[1001][1001] = { 0, };
bool visit[1001][1001] = { false };
int day[1001][1001] = { 0,}; //지난 날짜
int N, M;
int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, -1, 1, 0 };
bool inside(int a, int b)
{
	return (a >= 0 && a < M) && (b >= 0 && b < N);
}
void BFS(linkedqueue q)
{
	int a, b;
	while (!q.is_Empty())
	{
		Node* k = q.dequeue();
		a = k->get_data_x();
		b = k->get_data_y();
		visit[a][b] = true;
		free(k);
		for (int i = 0; i < 4; i++)
		{
			if (inside(a + x[i], b + y[i]) && arr[a + x[i]][b + y[i]] == 0 && !visit[a + x[i]][b + y[i]]) //배열안&&안익은토마토&&아직안갔을시
			{
				q.enqueue(new Node(a + x[i], b + y[i],NULL));
				visit[a + x[i]][b + y[i]] = true;
				arr[a + x[i]][b + y[i]] = 1;
				day[a + x[i]][b + y[i]] = day[a][b] + 1; //1일 지났으므로 +1을 해준다
			}
		}
	}
}

int main()
{
	int maxday =0;
	cin >> N >> M;
	linkedqueue tomato;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j]; //입력
			if (arr[i][j] == 1)
			{
				tomato.enqueue(new Node(i, j, NULL)); //익은 토마토일시 큐에 넣는다
			}
		}
	}
	BFS(tomato);
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0)  //안익은 토마토가 있을시
			{
				
				cout << "-1" << endl;
				return 0;
			}
			else
			{
				if (day[i][j]>maxday) //가장 큰 날짜를 찾는다
				{
					maxday = day[i][j];
				}
			}
		}
	}
	cout << maxday << endl;
	return 0;
}
