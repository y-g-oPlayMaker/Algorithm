#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
void zengLiangGouZao(int n,vector<int> N, vector<int> P, int now);
int main()
{
	cin >> n;
	vector<int> P(n);
	vector<int> N(n,0);
	for (auto &i : P)
	{
		int temp;
		cin >> temp;
		i = temp;
	}
	sort(P.begin(), P.end());
	zengLiangGouZao(n,N,P,0);
	cin >> n;
	return 0;
}

void zengLiangGouZao(int n, vector<int> N, vector<int> P, int now)
{
	for (int i = 0; i < now; i++)
	{
		cout << P[N[i]] << " ";
	}
	cout << endl;
	int s = now ? N[now - 1] + 1 : 0;
	for (int i = s; i < n; ++i)   
	{
		N[now]=i;
		zengLiangGouZao(n,N,P,now+1);
	}
}