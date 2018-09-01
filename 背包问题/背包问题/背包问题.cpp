#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,s,m;
int g=0;
bool comp(vector<int> elem1, vector<int> elem2);
int result(int m, vector<vector<int> > V);
int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> m;
		vector<vector<int> > V(s,vector<int>(2));       
		for (int j = 0; j < s; ++j)
		{
			cin >> V[j][0]>>V[j][1];     //>>价值>>重量
		}
		result(m,V);
		cout << g << endl;
		g = 0;
	}
	return 0;
}

int result(int m,vector<vector<int> > V)
{
 	sort(V.begin(), V.end(),comp);
	while(m)
	{
		if (V[0][1]>=m)
		{
			g += V[0][0]*m;
			return 0;
		}
		else if (V[0][1] < m)
		{
			m -= V[0][1];	
			g += V[0][0] * V[0][1];
			V.erase(V.begin());
		}
	}
	return 0;
}

	bool comp(vector<int> elem1, vector<int> elem2)
	{
		return elem1[0] > elem2[0];
	}

