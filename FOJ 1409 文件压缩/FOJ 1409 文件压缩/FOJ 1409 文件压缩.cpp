#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
unsigned n;
vector<char> S;
bool cmp(vector<char> a, vector<char> b);

int main()
{
	cin >> n;
	for (unsigned i = 0; i < n; ++i)
	{
		char temp;
		cin >> temp;
		S.push_back(temp);
	}
	vector<vector<char>> P{ n, };
	for (unsigned i = 0; i < n; ++i)
	{
		P[i].insert(P[i].begin(),S.begin()+i+1,S.end());
		P[i].insert(P[i].end(), S.begin(), S.begin() + i+1);
	}
	vector<char> Temp = P[0];
	sort(P.begin(), P.end(), cmp);
	for (unsigned i = 0; i < n; ++i)
	{
		cout << P[i][n - 1];
	}
	cout << endl;
	for (unsigned i = 0; i < n; ++i)
	{
		if (Temp == P[i])
		{
			cout << i + 1;
			break;
		}
	}
	cin >> n;
}



bool cmp(vector<char> a, vector<char> b)
{
	if (a[0] != b[0]) return a[0] < b[0];
	else return false;
}