#include <iostream>
#include <vector>
using namespace std;

class Node{ //스택을 위한 
private:
	int x;
	int y;
	Node* next;
public:
	Node(int a = 0, int b = 0, Node* link = NULL) //생성자
	{
		x = a;
		y = b;
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
	Node* pop()
	{
		Node* node = top;
		top = top->get_next_node();
		return node;
	}
};
int N;
vector <linked_stack > v;
int count = 0; //총 경우의 수
bool arr[16][16] = { false, };
bool inside(int a, int b) //체스판위에 있는지
{
	return (a >= 1 && a <= N) && (b >= 1 && b <= N);
}
void RCD(int a, int b) //행,열,대각선 확인
{
	linked_stack s;//바꾸면 그만큼 저장
	int tx, ty;
	for (int i = 1; i <= N; i++)
	{
		if (!arr[a][i]) //열
		{
			arr[a][i] = true;
			s.push(new Node(a, i));
		}
		if (!arr[i][b]) //행
		{
			arr[i][b] = true;
			s.push(new Node(i, b));
		}
	}
	tx = a;
	ty = b;
	while (inside(tx, ty)) //대각1
	{
		if (!arr[tx][ty])
		{
			arr[tx][ty] = true;

			s.push(new Node(tx, ty));
		}
		tx--;
		ty--;
	}
	tx = a;
	ty = b;
	while (inside(tx, ty))//대각2
	{
		if (!arr[tx][ty])
		{
			arr[tx][ty] = true;
			s.push(new Node(tx, ty));
		}
		tx--;
		ty++;
	}
	tx = a;
	ty = b;
	while (inside(tx, ty))//대각3
	{
		if (!arr[tx][ty])
		{
			arr[tx][ty] = true;
			s.push(new Node(tx, ty));
		}
		tx++;
		ty--;
	}
	tx = a;
	ty = b;
	while (inside(tx, ty))//대각4
	{
		if (!arr[tx][ty])
		{
			arr[tx][ty] = true;
			s.push(new Node(tx, ty));
		}
		tx++;
		ty++;
	}
	if (!s.is_empty())
	{
		v.push_back(s); //벡터에 저장
	}
}
void RCDR()//RCD함수의 반대역할(행,열,대각선을 다시바꾼다
{
	int x, y;
	linked_stack s = v.back();
	while (!s.is_empty())
	{
		Node* node = s.pop();
		x = node->get_data_x();
		y = node->get_data_y();
		arr[x][y] = false;
		free(node);
	}
	v.pop_back();
}
void Queen(int a, int num)
{
	if (num == 0) //다 배치했으면 
	{
		::count++;
		return;
	}
	for (int j = 1; j <= N; j++)
	{
		if (!arr[a][j]) //배치 할 수 있으면
		{
			RCD(a, j);
			Queen(a+1, num - 1);
			RCDR();
		}
	}
}
int main()
{
	cin >> N; //입력
	Queen(1,N);
	cout << ::count << endl; //
	return 0;
}
