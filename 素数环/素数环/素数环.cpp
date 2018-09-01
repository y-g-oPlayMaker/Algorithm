#include<iostream>
#include<vector>
using namespace std;
int n;
vector<bool> isp(24, false);
vector<bool> vis(25, false);
vector<int> A(24);
bool isprime(int n);
void dfs(int now);

int main()
{
	cin >> n;
	for (int i = 2; i <= n * 2; ++i)         //���ж�1~2n�е�ÿ�����ǲ�������
	{
		isp[i] = isprime(i);
	}
	A[0] = 1;
	dfs(1);                             //�ӵڶ�λ��ʼ�жϵ����һλ
	return 0;
}


void dfs(int now)
{
	if (n == now && isp[1+A[n - 1]])        //�ִ�ݹ�����ж����һ���͵�һ���Ƿ��ܷ��ϣ��������
	{

		for (int i=0;i<n;++i)
			cout << A[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if (isp[i + A[now - 1]] && !vis[i])       //vis�����洢��ǰ�����Ƿ�ʹ�ù�������iΪ�ȱ�����ң�vis�ĳ�ʼ��СΪn+1������Խ��
			{
				A[now] = i;
				vis[i] = true;
				dfs(now + 1);
				vis[i] = false;
			}
		}
	}
}


bool isprime(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}
