#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int s, w, n;
int cnt = 0;
int result(int w, vector<int> S);
int main()
{
	cin >> s;
	for (int i = 0; i < s; ++i)
	{
		cin >> w >> n;
		vector<int> S(n);
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin >> temp;
			S[j] = temp;
		}
		result(w, S);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

int result(int w, vector<int> S)
{
	sort(S.begin(), S.end());
	while (S.size() > 0)
	{
		if (S[0] + S[1] > w)
		{
			cnt += S.size();
			return 0;
		}
		while (S[0] + S[S.size() - 1] > w)
		{
			S.erase(S.begin() + (S.size() - 1));
			++cnt;
		}
		S.erase(S.begin());
		S.erase(S.begin() + (S.size() - 1));
		++cnt;
		if (S.size() == 1)
		{
			++cnt;
			break;
		}
	}
	return 0;
}