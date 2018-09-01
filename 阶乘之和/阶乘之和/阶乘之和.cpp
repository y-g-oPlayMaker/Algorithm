#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n = 0;
vector<int> N(9);
int result(vector<int> M);
int main()
{
	cin >> n;
	vector<int> M(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> M[i];
	}

	for (int j = 1; j < 10; ++j)            //Çó½×³Ë¿â    //10µÄ½×³ËÎª£º3628800
	{
		int ans = 1;
		for (int i = 1; i <= j; i++)
		{
			ans *= i;
		}
		N[j-1] = ans;
	}

	result(M);
	return 0;
}


int result(vector<int> M)
{
	reverse(N.begin(), N.end());
	for (vector<int>::iterator a=M.begin();a!=M.end();++a)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (*a >= N[i])
			{
				*a -= N[i];
			}
		}
		if (*a == 0)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}