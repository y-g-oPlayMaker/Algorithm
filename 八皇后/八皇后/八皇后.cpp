#include<iostream>
#include<vector>
using namespace std;
vector<vector<bool>> vis(3, vector <bool>(15, true));    // vis[0]�������Ƿ����vis[1],vis[2]����\��/�Ƿ�����
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


void huangHou(int n, vector<int>N, int now)                //nΪ��������N��������nowΪ��ǰ����
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
			if (vis[0][i] && vis[1][i - now + n] && vis[2][i + now])      //��һ�е�����һ��ʱ�Ե�
			{
				N[now] = i;                               //�����������ͬʱ���ϣ�����ǰ�е����������긳ֵΪi
				vis[0][i] = vis[1][i - now + n] = vis[2][i + now] = false;//i-now+n Ϊy-x\���б��+n����������0~14�䣬i+nowΪx+y/��һб��
				huangHou(n, N, now + 1);
				vis[0][i] = vis[1][i - now + n] = vis[2][i + now] = true;//��Ϊʱȫ�ֱ��������Իص��ϲ�ʱҪ����һ��i����Ӧ��vis�ĸ�д�ĸ�ԭ
			}
		}
}