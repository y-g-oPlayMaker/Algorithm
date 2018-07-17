#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> number(18,0);//创建用于存储元素的向量；
int n;//输入元素个数
int _count=0;//元素组数下标计数器；
int resultCount = 0;//结果下标计数器
vector<long long> result(171,1);
vector<long long>_max(18,0);
int main()
{
	int a;
	while (cin >> n)
	{
		//输入部分；
		for (int i = 0; i < n; ++i)//
		{
			cin >> a;
			number[i] = a;
		}

		for (unsigned i = 0; i < n; i++)//i为头，最后一次为头移至n-1；
		{
			for (unsigned j = n; i<j; --j)//j为尾后，最后一次为每次头的位置+1；
			{
				for (unsigned k = i; k <j ; ++k)//每次均为从头累乘至尾；
				{
					result[resultCount] *= number[k];//存入每次结果存入result中第n-j位置；即尾后每动一次存一次；
				}
				++resultCount;
			}
		}
		 _max[_count]=*max_element(result.begin(), result.begin()+n);//将result向量中最大的存入_max向量
		 resultCount = 0;//结果计数器清零，重新覆写result
		 for (; 0 < n; --n)
			 result[n - 1] = 1;
		++_count;//元素组数计数器+1
	}
	for (int i=0;i<_count;++i)
	{
		if (_max[i] < 0)
			cout << -1 << endl;
		else
			cout << _max[i] << endl;

	}
	system("pause");
	return 0;
}