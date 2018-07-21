#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> P(n,0);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin >> temp;
		P[i] = temp;
	}
	sort(P.begin(), P.end()); //排序，得到P的最小排列；
	do
	{
		for (auto i : P)       //输出排列p
			cout << i << " ";
		cout << endl;
	} while (next_permutation(P.begin(), P.end()));//求下一个排列
	return 0;
}