#include<iostream>
using namespace std;
int n;
void erJinZhiQiuZiJI(int n, int s);

//���ö�����ģ��λ���뼯����Ԫ��������0��1��ʾ������ λ������0~n-1��Ԫ�أ�ֵ0��1��������ȫ�Ӽ����Ǳ�1 0 0 0 0 0 0 0 0 0 0 0 0 0С�����зǸ�������0Ϊ�ռ���
int main()																		//      			n * * * * * * * * * * * * 0
{
	cin >> n;
	for (int i = 0; i < (1 << n); ++i)      //��0��nλ�Ķ�������-1�����ϵ��ú��������ǰ�ּ���
	{
		erJinZhiQiuZiJI(n, i);       
	}
	cin >> n;
	return 0;
}

void erJinZhiQiuZiJI(int n, int s)//n������Ҳ��������һ����nλ��0~n-1��
								  //sΪ��ǰҪ������Ӽ������б�nλ������ת����ʮ������С�ķǸ�������
{
	for (int i = 0; i < n; ++i)
	{
		if (s&(1 << i))			  //�����Ƶ�ǰ��iλ(1 << i)��s����&���㣬��s�ĵ�iλҲ��1(����)�����Ϊ1
			cout << i << " ";	  //�����ǰλ����ż���������֣�
	}
	cout << endl;
}