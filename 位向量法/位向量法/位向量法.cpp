#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
void weiXiangLiang(int n, vector <bool> N, vector<int> P, int now);

int main()
{
	cin >> n;
	vector<int> P(n);
	vector<bool> N(n,false);
	for (auto &i : P)
	{
		int temp;
		cin >> temp;
		i = temp;
	}
	sort(P.begin(), P.end());
	weiXiangLiang(n, N, P, 0);
	cin >> n;
	return 0;
}

void weiXiangLiang(int n, vector <bool> N, vector<int> P, int now)
{
	if (now == n)
	{
		for (int i = 0; i < now; ++i)
		{
			if (N[i])
				cout << P[i] << " ";
		}
		cout << endl;
	}
	else
	{
		N[now] = true;
		weiXiangLiang(n, N, P, now + 1);
		N[now] = false;
		weiXiangLiang(n, N, P, now + 1);
	}
}
