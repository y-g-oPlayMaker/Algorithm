#include<iostream>
#include<vector>
using namespace std;
void solution(int &A, int &B, vector<int> &x, vector<int> &y, int n)       //枚举法判断从x，y=-500~500的各条线两端的点是否相同，并不用判断是否在线上；
{
	for (A = -500; A <= 500; A++) 
	{
		for (B = -500; B <= 500; B++) 
		{
			int d = 0, u = 0;
			for (int i = 0; i < 2 * n; i++) 
			{
				if (A*x[i] + B * y[i] > 0) u++;
				if (A*x[i] + B * y[i] < 0) d++;
			}
			if (u == n && d == n) return;
		}
	}
}
int main()
{
	int n;
	while (cin >> n && n != 0) 
	{
		vector<int> x(2 * n, 0);
		vector<int> y(2 * n, 0);
		for (int i = 0; i < 2 * n; i++) 
		{
			cin >> x[i] >> y[i];
		}
		int A, B;
		solution(A, B, x, y, n);
		cout << A << ' ' << B << endl;
	}
	return 0;
}