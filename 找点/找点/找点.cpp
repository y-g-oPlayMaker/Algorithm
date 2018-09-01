#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
int cnt=0;
bool falg = false;
int result(vector<vector<int> > S);
bool comp(vector<int> a, vector<int> b);
int main()
{
	while (cin >> n)
	{
		vector<vector<int> > S(n,vector<int>(2));
		for (int i = 0; i < n; ++i)
		{
			cin >> S[i][0] >> S[i][1];
		}
		result(S);
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}

int result(vector<vector<int> > S)
{
	sort(S.begin(), S.end(),comp);
	for (int i = 0; i < S.size(); ++i)
	{	
		vector<vector<int> >::iterator it = S.begin()+i+1;
		for (;; ++it)
		{
			while (it != S.end() &&(*it)[0]<=S[i][1] && S[i][1] <= (*it)[1])
			{
				it = S.erase(it);
			}
			if (it == S.end())
			{
				break;
			}
		}
	}
	cnt += S.size();
	return 0;
}

bool comp(vector<int> a,vector<int> b)
{
	return a[1] <b[1];
}
