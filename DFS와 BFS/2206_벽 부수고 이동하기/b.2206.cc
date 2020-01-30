/* 벽을 부셨을때의 visit을 새로 작성해야한다*/

#include <iostream>
#pragma warning (disable:4996)
using namespace std;

class Node //큐를 위한 노드
{
public:
	int x;
	int y;
	bool destroy;  //벽을 부섰는지 확인
	Node* next;
	Node(int a = 0, int b = 0, bool d = false, Node* link = NULL) //생성자
	{
		x = a;
		y = b;
		destroy = d;
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
	bool get_data_destroy()
	{
		return destroy;
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

int arr[1000][1000] = { 0, };
bool visit[1000][1000] = { false };
bool visitD[1000][1000] = { false }; //벽을 부수고 
int depth[1000][1000] = { 0, }; //지나야 하는 최소의 칸 수
bool flag = false; //출력했는지
int N, M;
int x[4] = { -1, 0, 0, 1 };
int y[4] = { 0, -1, 1, 0 };
bool inside(int a, int b)
{
	return (a >= 0 && a < N) && (b >= 0 && b < M);
}
void BFS(int a, int b)
{
	linkedqueue q;
	bool wall;
	q.enqueue(new Node(a, b,false, NULL));
	visit[a][b] = true;
	depth[a][b] = 1;
	while (!q.is_Empty())
	{
		Node* k = q.dequeue();
		a = k->get_data_x();
		b = k->get_data_y();
		wall = k->get_data_destroy();
		free(k);
		if ((a == N - 1) && (b == M - 1)) //출구로 도착하면 출력후 종료
		{
			cout << depth[a][b] << endl;
			flag = true; //출력했는지
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			if (!wall) //벽을 안부셨을시
			{
				if (inside(a + x[i], b + y[i]) && !visit[a + x[i]][b + y[i]] && (arr[a + x[i]][b + y[i]] == 1)) //부수고 지나감
				{
					q.enqueue(new Node(a + x[i], b + y[i],true));
					visit[a + x[i]][b + y[i]] = true;
					depth[a + x[i]][b + y[i]] = depth[a][b] + 1; //한칸 지났으므로 +1을 해준다
				}
				else
				{
					if (inside(a + x[i], b + y[i]) && !visit[a + x[i]][b + y[i]] && (arr[a + x[i]][b + y[i]] == 0)) //안부수고 지나감
					{
						q.enqueue(new Node(a + x[i], b + y[i]));
						visit[a + x[i]][b + y[i]] = true;
						depth[a + x[i]][b + y[i]] = depth[a][b] + 1; //한칸 지났으므로 +1을 해준다
					}
				}
			}
			else//벽을 부셨을시
			{
				if (inside(a + x[i], b + y[i]) && !visitD[a + x[i]][b + y[i]] && (arr[a + x[i]][b + y[i]] == 0))
				{
					q.enqueue(new Node(a + x[i], b + y[i],true));
					visitD[a + x[i]][b + y[i]] = true; //visitD에 따로 저장
					depth[a + x[i]][b + y[i]] = depth[a][b] + 1; //한칸 지났으므로 +1을 해준다
				}
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
	BFS(0, 0);
	if (!flag) //아무것도 출력하지 않았을 때==출구까지 도달 못했을시
	{
		cout << "-1" << endl;
	}
	return 0;
}
