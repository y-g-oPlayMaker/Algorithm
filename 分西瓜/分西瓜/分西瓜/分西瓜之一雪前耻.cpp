#include<iostream>
#include<vector>
using namespace std;
int n;
int min2 = 0;
int min = INT_MAX;
int sum = 0;
void zengLiangGouZao(int n, vector<int> N, vector<int> P, int now)
{
	for (int i = 0; i < now; i++)
	{
		min2 = sum - 2 * P[N[i]];
	}

	if (now&&min > abs(min2))
	{
		min = abs(min2);
	}
	int s = now ? N[now - 1] + 1 : 0;
	for (int i = s; i < n; ++i)
	{
		N[now] = i;
		zengLiangGouZao(n, N, P, now + 1);
	}
}

int main()
{
	cin >> n;
	vector<int> P(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> P[i];
		sum += P[i];
	}
	vector<int> N(n,0);
	zengLiangGouZao(n, N, P, 0);
	cout << min;
	cin >> n;
	return 0;
}


