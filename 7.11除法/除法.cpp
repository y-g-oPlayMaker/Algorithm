#include<iostream>
#include<vector>
using namespace std;
int n;
bool flag = true;//���ñ�־Ϊ��
vector<int> beiChuShu, chuShu,bcs , cs;//����beiChuShu��chuShu�����������ͳ�����ѡ������bcs,cs,Ϊ��������
vector<int> number1(5, 0), number2(5, 0);//����������������
int main()
{
	cin >> n;//����������

	for (int i = 1000; i < 50000; i++)//�˴�ѭ��ɸѡ�����ظ�����������chuShu���������Ӧ��ѡ����������beiChuShu;
	{
		int l = i;
		for (int m = 0; m < 5; ++m)//���ѭ������ǰi��1000-10000���еĸ�λ������ȡ������number[0-4]
		{
			number1[m] = l % 10;
			l /= 10;
		}
		for (int p = 0; p < 5; ++p)//�жϸ������Ƿ����λ���ظ�
		{
			for (int n = p + 1; n < 5; ++n)//�жϵ�ǰλ�����ֺ����������Ƿ���ͬ
				if (number1[p] == number1[n])
					flag = false;
		}
		if (flag)//���i���������ظ�����i���������n*i���뱻��������������
		{
			chuShu.push_back(i);
			beiChuShu.push_back(n*i);
		}
		flag = true;//���ñ�־
	}

	for (unsigned a = 0; a < beiChuShu.size(); ++a)//��ѭ��ɸѡ����ѡ�������в��ظ��Ĳ��ַ�������bcs��cs
	{
		if (beiChuShu[a] < 100000)
		{
			int l = beiChuShu[a];
			for (int m = 0; m < 5; ++m)//���ѭ������ǰbeichushu�����еĸ�λ������ȡ������number[0-4]
			{
				number1[m] = l % 10;
				l /= 10;
			}
			for (int p = 0; p < 5; ++p)//�жϸ������Ƿ����λ���ظ�
			{
				for (int n = p + 1; n < 5; ++n)//�жϵ�ǰλ�����ֺ����������Ƿ���ͬ
					if (number1[p] == number1[n])
						flag = false;
			}

			l = chuShu[a];
			for (int m = 0; m < 5; ++m)//���ѭ������ǰbeichushu�����еĸ�λ������ȡ������number[0-4]
			{
				number2[m] = l % 10;
				l /= 10;
			}
			for (int p = 0; p < 5; ++p)//�жϸ������Ƿ����λ���ظ�
			{
				for (int n = p + 1; n < 5; ++n)//�жϵ�ǰλ�����ֺ����������Ƿ���ͬ
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
			flag = true;//���ñ�־
		}
	}

	if (cs.size() == 0)
		cout << "������";
	else 
	{
		for (unsigned a = 0; a < cs.size(); ++a)
		{
			cout << bcs[a] << "/" << cs[a] << "=" << n << endl;
		}
	}
	return 0;
}		