#include<iostream>;
#include<vector>;
using namespace std;
int dfs(int now,vector<char> S);
int L;
int n;

int main()
{
	cin >> n;
	cin >> L;
	vector<char> S(n,'A');
	dfs(1,S);
	return 0;
}



int dfs(int now,vector<char> S)
{
	if (now == n)
	{
		for (int i = 0; i < now-1; ++i)
			cout<< S[i];
		cout << endl;
		return 0;
	}
	for (int i = 0; i < L; ++i)
	{
		S[now] = 'A';
		S[now] +=i;
		bool flag = true;
		for (int j = 1; j * 2 <= now + 1; ++j)
		{
			bool equal = true;
			for (int k = 0; k < j; ++k)
			{
				if (S[now - k] != S[now - k - j])
				{
					equal = false; break;
				}

			}
			if (equal)
			{
				flag = false; break;
			}
		}
			if (flag)
			{
				if (!dfs(now + 1,S))
				{
					return 0;
				}
			}
	}
	return 1;
}