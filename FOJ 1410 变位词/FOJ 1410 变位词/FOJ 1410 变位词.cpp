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
	getchar();//����Իس�
	for (unsigned i = 0; i < n; ++i)
	{
		string temp;
		getline(cin, temp);
		S.push_back(temp);
	}
	cin >> m;
	getchar();//����Իس�
	for (unsigned i = 0; i < m; ++i)
	{
		string temp;
		getline(cin, temp);
		L.push_back(temp);
	}
	//������ĿҪ���������Ϊ100000������*ÿ������������д���9*9  + 100���������� +100����*ÿ�������ֵ�ȶ�100000
	//����2000w��С��25������ֱ�Ӽ򵥴ֱ�����������Ա�
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