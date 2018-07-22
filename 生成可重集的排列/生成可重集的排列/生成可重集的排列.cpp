#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
void keChongPaiLie(int n, vector<int> N, vector<int> P, int now);

int main()
{
	cin >> n;
	vector<int> Number(n, 0);
	vector<int> P(n, 0);
	int temp;
	for (int i = 0; i < n; ++i)
	{
		cin >> temp;
		P[i] = temp;
	}
	sort(P.begin(), P.end());
	keChongPaiLie(n, Number, P, 1);
	cin >> n;
	return 0;
}


void keChongPaiLie(int n,vector<int> N,vector<int> P,int now)
{
	if (n < now)
	{
		for (auto i : N)
			cout << i << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (!i || P[i] != P[i - 1])
			{
				int _count1 = count(P.begin(),P.end(),P[i]);
				int _count2 = count(N.begin(),N.begin()+now,P[i]);
				if (_count2 < _count1)
				{
					N[now-1] = P[i];
					keChongPaiLie(n, N, P, now + 1);
				}
			}
		}
	}
}