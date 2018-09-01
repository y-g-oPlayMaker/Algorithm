#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
char n[1000];
char m;
int _min = 999;
int dis2 = 0;
int ct = 0;
map<char, vector<char>> point;
vector<char> P; 
vector<char> End;
void solution(int now);
int main()
{
	cin >> n;
	while (1)
	{
		if (n[ct++] == ':')
		{	
			m = n[ct - 2];
			P.push_back(m);
			while (1)
			{
				if (n[ct] == ';' || n[ct] == '#')
					break;
				point[m].push_back(n[ct]);
				P.push_back(n[ct]);
				++ct;
			}
		}
		if (m == '#' || n[ct] == '#')
			break;
	}

	sort(P.begin(), P.end());
	P.erase(unique(P.begin(), P.end()), P.end());


	solution(1);
	for (auto i : End)
		cout << i<<' ';
	cout << endl;
	return 0;
}

void solution(int now)
{
	vector<int> number(point.size());
	bool flag = true;
	for (int i = 0; i < point.size(); ++i)
	{
		for (int j = 0; j < now; ++j)
			if (number[j] = i)
			{
				flag = false;
			}
		if (flag)
		{
			int dis1;
			number[now - 1] = i;
			for (int j = 0; j < now; ++j)
				for (vector<char>::iterator k = point[P[number[j]]].begin(); k < point[P[number[j]]].end(); ++k)
					if (point.find(P[number[j]]) != point.end()&&P[number[j]] == *k)
					{
						dis1 = number[j] - (k - point[P[number[j]]].begin());
						if (dis2 < dis1)
							dis2 = dis1;
					}
			if (_min < dis2)
				continue;
			else
			{
				_min = dis2;
				End = P;
			}
			solution(now + 1);
		}
	}
}