#include <iostream>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
using namespace std;
const int MAX_OPT = 100;
int opt[MAX_OPT];
char opt_name[][5] = { "ADD", "SUB", "SUL", "DIV", "DUP" };
int a, b;

struct node

{
	string pre;//֮ǰ�Ĳ���
	int op; //��ǰ���� 0:ADD, 1:SUB, 2:SUL, 3:DIV, 4DUP
	stack<int> s; //����ջ
};

queue<node> q; //����
node n;

//������ջ��������

void op()
{
	int a, b;
	if (n.op != 4) {
		a = n.s.top(); n.s.pop();
		b = n.s.top(); n.s.pop();
	}
	else {
		a = n.s.top();
	}

	switch (n.op)
	{
	case 0: n.s.push(a + b); break;
	case 1: n.s.push(b - a); break;
	case 2: n.s.push(a*b); break;
	case 3: n.s.push(b / a); break;
	case 4: n.s.push(a); break;
	}
	n.pre += (char)(n.op + '0');
}

//���ջ�Ͷ���
void clear_st_q()
{
	while (n.s.size())
	{
		n.s.pop();
	}
	while (q.size())
	{
		q.pop();
	}
}

//��ȱ���

void bfs()
{
	//�տ�ʼֻ���Խ���DUP����
	n.op = 4;//dup
	n.pre = "";
	n.s.push(a);
	q.push(n);
	while (!q.empty())
	{
		n = q.front();
		q.pop();
		op();
		int top = n.s.top();
		if (n.s.top() == b) return;
		for (int i = 0; i < 5; i++)
		{
			n.op = i;
			switch (i)
			{
			case 0:
			case 1:
			case 2:
			case 3:
				if (n.s.size() < 2) break;
				if (i == 3 && top == 0) break;
			case 4:
				q.push(n);
			}
		}
	}
}



int main(void) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	//����a b
	while (scanf("%d%d", &a, &b) == 2)
	{
		bfs();
		string s = n.pre;
		for (size_t i = 0; i < s.size(); i++)
		{
			printf("%s\n", opt_name[s[i] - '0']);
		}
		printf("\n");
		clear_st_q();
	}
	return 0;
}
