#include<iostream>
using namespace std;
int n;
void erJinZhiQiuZiJI(int n, int s);

//利用二进制模型位数与集合中元素有无用0，1表示的相似 位数代表0~n-1个元素，值0，1代表有无全子集就是比1 0 0 0 0 0 0 0 0 0 0 0 0 0小的所有非负整数（0为空集）
int main()																		//      			n * * * * * * * * * * * * 0
{
	cin >> n;
	for (int i = 0; i < (1 << n); ++i)      //从0到n位的二进制数-1，不断调用函数输出当前字集合
	{
		erJinZhiQiuZiJI(n, i);       
	}
	cin >> n;
	return 0;
}

void erJinZhiQiuZiJI(int n, int s)//n个数，也就是序列一共有n位，0~n-1，
								  //s为当前要输出的子集（所有比n位二进制转换成十进制数小的非负整数）
{
	for (int i = 0; i < n; ++i)
	{
		if (s&(1 << i))			  //二进制当前第i位(1 << i)与s做与&运算，当s的第i位也是1(存在)结果才为1
			cout << i << " ";	  //输出当前位的序号即代表的数字；
	}
	cout << endl;
}