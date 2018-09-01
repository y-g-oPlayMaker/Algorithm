#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
float c, a, b;
int n;
int _max=0;
int _min = 999;
size_t _maxNumber;
size_t ct;
bool flag = false;
vector<vector<int>> Number(100,vector<int>(100,0));
void solution(int n, int now);
void compare();
int main()
{
	cin >> a >> b;
	c = a/b;
	for (int i = 10;; ++i)
	{
		solution(i, 1);
		if (flag)
		{
			break;
		}
	}
	compare();
	for (int i=0;i<_min;++i)
		cout << i << ' ';
	cout << endl;
	return 0;
}


void solution(int n,int now)
{
	for (float i = 2; i < n; ++i)
	{
		if (c - (1 / i)>0)
		{
			c -= 1 / i;
			Number[ct][now-1]=i;
			if (c < 0.000001)
			{
				++ct;
				c = a / b;
				flag = true;
				if (now < _min)
					_min = now;
				break;
			}
			solution(n, now + 1);
		}	
	}

}

void compare()
{
	for (int i = 0; i < Number.size(); ++i)
	{
		auto maxPosition = max_element(Number[i].begin(), Number[i].end());
		if (_max < *maxPosition)
		{
			_max = *maxPosition;
			_maxNumber = i;
		}
	}
}