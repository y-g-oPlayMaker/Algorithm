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
	sort(P.begin(), P.end()); //���򣬵õ�P����С���У�
	do
	{
		for (auto i : P)       //�������p
			cout << i << " ";
		cout << endl;
	} while (next_permutation(P.begin(), P.end()));//����һ������
	return 0;
}