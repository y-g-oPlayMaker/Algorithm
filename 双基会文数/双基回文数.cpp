#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n;
int i;
bool flag = true;
int result = 0;
int _count = 0;
int _count2 = 0;
vector<int> number(25, 0);
int main()
{
	cin >> n;
	for (i = n; i < 10000000; ++i)
	{
		for (int j = 2; j <= 10; ++j)
		{
			int a = i, b = i;
			for (int p = 0; p < log(i) / log(j); ++p)
			{
				while (a)
				{
					a = a / j;
					if (a)
						++_count;
				}
				if (b)
				{
					number[_count] = b / pow(j, _count);
					a = b - number[_count]*pow(j, _count);
					b = a;
					_count = 0;
					++_count2;
				}
			}
			for (unsigned m = 0; m < (int(log(i) / log(j))+1) / 2; ++m)
			{
				if (number[m] != number[int(log(i) / log(j)) - m])
				{
					flag = false;
					break;
				}
			}
			if (flag&& (int(log(i) / log(j)) + 1) / 2)
				++result;
			_count2 = 0;
			flag = true;
			for (int p = 0; p < number.size(); ++p)
			{
				number[p] = 0;
			}
		}
		if (result >= 2)
			break;
		result = 0;
	}
	cout << i;
	cin >> i;
	return 0;
}