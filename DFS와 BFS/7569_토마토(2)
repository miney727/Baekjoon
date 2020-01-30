#include <iostream>
using namespace std;

class Node //큐를 위한 노드
{
public:
	int x;
	int y;
	int z;
	Node* next;
	Node(int a = 0, int b = 0,int c=0, Node* link = NULL) //생성자
	{
		x = a;
		y = b;
		z = c;
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
	int get_data_z()
	{
		return z;
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

int arr[100][100][100] = { 0, };
bool visit[100][100][100] = { false };
int day[100][100][100] = { 0, }; //지난 날짜
int N, M, H;
int x[6] = { -1, 0, 0, 1, 0, 0 };
int y[6] = { 0, -1, 1, 0, 0, 0 };
int z[6] = { 0, 0, 0, 0, 1, -1 };
bool inside(int a, int b, int c)
{
	return (a >= 0 && a < M) && (b >= 0 && b < N)&&(c>=0&&c<H);
}
void BFS(linkedqueue q)
{
	int a, b, c;
	while (!q.is_Empty())
	{
		Node* k = q.dequeue();
		a = k->get_data_x();
		b = k->get_data_y();
		c = k->get_data_z();
		visit[a][b][c] = true;
		free(k);
		for (int i = 0; i < 6; i++)
		{
			if (inside(a + x[i], b + y[i], c + z[i]) && arr[a + x[i]][b + y[i]][c + z[i]] == 0 && !visit[a + x[i]][b + y[i]][c + z[i]]) //배열안&&안익은토마토&&아직안갔을시
			{
				q.enqueue(new Node(a + x[i], b + y[i],c+z[i],NULL));
				visit[a + x[i]][b + y[i]][c + z[i]] = true;
				arr[a + x[i]][b + y[i]][c + z[i]] = 1;
				day[a + x[i]][b + y[i]][c + z[i]] = day[a][b][c] + 1; //1일 지났으므로 +1을 해준다
			}
		}
	}
}

int main()
{
	int maxday =0;
	cin >> N >> M>>H;
	linkedqueue tomato;
	for (int k = 0; k < H; k++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j][k]; //입력
				if (arr[i][j][k] == 1)
				{
					tomato.enqueue(new Node(i, j,k, NULL)); //익은 토마토일시 큐에 넣는다
				}
			}
		}
	}
	BFS(tomato);
	for (int k = 0; k < H;k++)
	{ 
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j][k] == 0)  //안익은 토마토가 있을시
				{
					cout << "-1" << endl;
					return 0;
				}
				else
				{
					if (day[i][j][k]>maxday) //가장 큰 날짜를 찾는다
					{
						maxday = day[i][j][k];
					}
				}
			}
		}
	}
	cout << maxday << endl;
	return 0;
}
