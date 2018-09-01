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
	for (int i = 2; i <= n * 2; ++i)         //先判断1~2n中的每个数是不是素数
	{
		isp[i] = isprime(i);
	}
	A[0] = 1;
	dfs(1);                             //从第二位开始判断到最后一位
	return 0;
}


void dfs(int now)
{
	if (n == now && isp[1+A[n - 1]])        //抵达递归基，判断最后一个和第一个是否能符合，输出序列
	{

		for (int i=0;i<n;++i)
			cout << A[i] << " ";
		cout << endl;
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{
			if (isp[i + A[now - 1]] && !vis[i])       //vis向量存储当前数字是否使用过，就用i为秩避免混乱，vis的初始大小为n+1，不会越界
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
