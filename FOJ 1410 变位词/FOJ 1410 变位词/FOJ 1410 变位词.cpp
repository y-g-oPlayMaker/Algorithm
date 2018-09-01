#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
unsigned n;
unsigned m;
int cnt;
vector<string> S;
vector<string> L;
int main()
{
	cin >> n;
	getchar();//负责吃回车
	for (unsigned i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		S.push_back(temp);
	}
	cin >> m;
	getchar();//负责吃回车
	for (unsigned i = 0; i < m; ++i)
	{
		string temp;
		getline(cin, temp);
		L.push_back(temp);
	}
	//由于题目要求最大运行为100000次排序*每次排序最大运行次数9*9  + 100个单词排序 +100个词*每个词与字典比对100000
	//奖金2000w次小于25亿所以直接简单粗暴排序再逐个对比
	for (unsigned i = 0; i < S.size(); ++i)
	{
		sort(S[i].begin(), S[i].end());
	}
	for (unsigned i = 0; i < L.size(); ++i)
	{
		sort(L[i].begin(), L[i].end());
	}
	for (unsigned i = 0; i < L.size(); ++i)
	{
		for (unsigned j = 0; j < S.size(); ++j)
		{
			if (L[i] == S[j])
				cnt++;
		}
		cout << cnt << endl;
		cnt = 0;
	}
}