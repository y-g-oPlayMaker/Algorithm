#include<iostream>
#include<vector>
using namespace std;
int n;
void paiLie(int n, vector<int> Number, int now);
int main()
{
	cin >> n;
	vector<int> Number(n, 0);
	paiLie(n, Number, 1);
	cin >> n;
	return 0;
}

void paiLie(int n, vector<int> Number, int now)
{
	if (n < now)
	{
		for (auto i : Number)
			cout << i << " ";
		cout << endl;
	}
	else
		for (int i = 1; i <= n; ++i)
		{
			bool flag = true;
			for (int j = 0; j < now; ++j)
			{
				if (Number[j] == i)
					flag = false;
			}
			if (flag)
			{
				Number[now - 1] = i;
				paiLie(n, Number, now + 1);
			}
		}
}