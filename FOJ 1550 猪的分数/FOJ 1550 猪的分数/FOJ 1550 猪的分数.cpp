#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n;
bool cmp(map<int, int>::iterator a, map<int, int>::iterator b)
{
	if (a->first != b->first&&a->second != b->second)
		return a->first / a->second > b->first / b->second;
}
int main()
{
	while (cin >> n)
	{
		cout << "0/1" << endl;
		map<int, int> M;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = n; j > 0; --j)
			{
				if (i == 1)
				{
					M.insert(make_pair(i, j));
				}
				else if (i < j&&j%i != 0)
				{
					M.insert(make_pair(i, j));
				}
			}
		}		M.erase((1, 1));
		sort(M.begin(), M.end(),cmp);

		for (map<int, int>::iterator it = M.begin(); it != M.end(); ++it)
		{
			cout << it->first << "/" << it->second << endl;
		}
		cout << "1/1";
	}
}//暂时没有考虑到sort函数不支持map容器。


//网上的oj代码，Gnu c++，也用的map，不过思路是转换成字符串做的。
#include <map>  
#include <string>  
#include <iostream>  
#include <stdio.h>  
using namespace std;


int main()
{
	int N;
	string s3 = "    ";
	char a[160];
	char b[160];
	memset(a, '/0', 10);
	memset(b, '/0', 10);
	map < double, string > number;
	map < double, string >::iterator iter;
	while (cin >> N)
	{
		number.insert(map < double, string >::value_type(0.00, "0/1"));
		if (N != 1)
			number.insert(map < double, string >::value_type(0.50, "1/2"));
		number.insert(map < double, string >::value_type(1.00, "1/1"));
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				if (i%j == 0 && j != 1)          //能整除的,不是真分数  
					continue;
				else
				{
					sprintf(a, "%d", j);      //把整型转换成字符串  
					string s1(a);
					sprintf(b, "%d", i);
					string s2(b);
					s3 = s1 + "/" + s2;
					number.insert(map < double, string >::value_type((1.00 / i)*j, s3));
				}
			}
		}
		for (iter = number.begin(); iter != number.end(); iter++)
		{
			cout << iter->second << endl;
		}
		number.clear();
	}
	return 0;
}