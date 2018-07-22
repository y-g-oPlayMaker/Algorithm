#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool>> vis(3, vector <bool>(15, true));    // vis[0]代表列是否能填，vis[1],vis[2]代表\和/是否能填
int n;
void huangHou(int n, vector<int>N, int now);
int main()
{
	cin >> n;
	vector<int> N(n, 0);
	huangHou(n, N, 0);
	cin >> n;
	return 0;
}


void huangHou(int n, vector<int>N, int now)                //n为行列数，N保存结果，now为当前计数
{
	if (now == n)
	{
		for (auto i : N)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	else
		for (int i = 0; i < n; ++i)
		{
			if (vis[0][i] && vis[1][i - now + n] && vis[2][i + now])      //第一行的棋子一定时对的
			{
				N[now] = i;                               //如果三个条件同时符合，将当前行的棋子列坐标赋值为i
				vis[0][i] = vis[1][i - now + n] = vis[2][i + now] = false;//i-now+n 为y-x\这个斜排+n将排数置于0~14间，i+now为x+y/这一斜排
				huangHou(n, N, now + 1);
				vis[0][i] = vis[1][i - now + n] = vis[2][i + now] = true;//因为时全局变量，所以回到上层时要将上一次i所对应的vis的改写的复原
			}
		}
}