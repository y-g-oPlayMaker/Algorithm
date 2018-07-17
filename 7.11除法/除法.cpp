#include<iostream>
#include<vector>
using namespace std;
int n;
bool flag = true;//设置标志为真
vector<int> beiChuShu, chuShu,bcs , cs;//设置beiChuShu，chuShu两个被除数和除数候选容器；bcs,cs,为最终容器
vector<int> number1(5, 0), number2(5, 0);//容纳五个输入的向量
int main()
{
	cin >> n;//输入所求结果

	for (int i = 1000; i < 50000; i++)//此大循环筛选出不重复除数，存入chuShu，并求出对应候选被除数存入beiChuShu;
	{
		int l = i;
		for (int m = 0; m < 5; ++m)//五次循环将当前i（1000-10000）中的各位的数字取出存入number[0-4]
		{
			number1[m] = l % 10;
			l /= 10;
		}
		for (int p = 0; p < 5; ++p)//判断该数字是否各个位不重复
		{
			for (int n = p + 1; n < 5; ++n)//判断当前位的数字和其他数字是否相同
				if (number1[p] == number1[n])
					flag = false;
		}
		if (flag)//如果i中数字五重复，把i存入除数，n*i存入被除数，否则跳过
		{
			chuShu.push_back(i);
			beiChuShu.push_back(n*i);
		}
		flag = true;//重置标志
	}

	for (unsigned a = 0; a < beiChuShu.size(); ++a)//此循环筛选出候选被除数中不重复的部分放入最终bcs和cs
	{
		if (beiChuShu[a] < 100000)
		{
			int l = beiChuShu[a];
			for (int m = 0; m < 5; ++m)//五次循环将当前beichushu向量中的各位的数字取出存入number[0-4]
			{
				number1[m] = l % 10;
				l /= 10;
			}
			for (int p = 0; p < 5; ++p)//判断该数字是否各个位不重复
			{
				for (int n = p + 1; n < 5; ++n)//判断当前位的数字和其他数字是否相同
					if (number1[p] == number1[n])
						flag = false;
			}

			l = chuShu[a];
			for (int m = 0; m < 5; ++m)//五次循环将当前beichushu向量中的各位的数字取出存入number[0-4]
			{
				number2[m] = l % 10;
				l /= 10;
			}
			for (int p = 0; p < 5; ++p)//判断该数字是否各个位不重复
			{
				for (int n = p + 1; n < 5; ++n)//判断当前位的数字和其他数字是否相同
					if (number2[p] == number2[n])
						flag = false;
			}

			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0; j < 5; ++j)
				{
					if (number1[i] == number2[j])
						flag = false;
				}
			}

			if (flag)
			{
				cs.push_back(chuShu[a]);
				bcs.push_back(beiChuShu[a]);
			}
			flag = true;//重置标志
		}
	}

	if (cs.size() == 0)
		cout << "不存在";
	else 
	{
		for (unsigned a = 0; a < cs.size(); ++a)
		{
			cout << bcs[a] << "/" << cs[a] << "=" << n << endl;
		}
	}
	return 0;
}		