#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> number(18,0);//�������ڴ洢Ԫ�ص�������
int n;//����Ԫ�ظ���
int _count=0;//Ԫ�������±��������
int resultCount = 0;//����±������
vector<long long> result(171,1);
vector<long long>_max(18,0);
int main()
{
	int a;
	while (cin >> n)
	{
		//���벿�֣�
		for (int i = 0; i < n; ++i)//
		{
			cin >> a;
			number[i] = a;
		}

		for (unsigned i = 0; i < n; i++)//iΪͷ�����һ��Ϊͷ����n-1��
		{
			for (unsigned j = n; i<j; --j)//jΪβ�����һ��Ϊÿ��ͷ��λ��+1��
			{
				for (unsigned k = i; k <j ; ++k)//ÿ�ξ�Ϊ��ͷ�۳���β��
				{
					result[resultCount] *= number[k];//����ÿ�ν������result�е�n-jλ�ã���β��ÿ��һ�δ�һ�Σ�
				}
				++resultCount;
			}
		}
		 _max[_count]=*max_element(result.begin(), result.begin()+n);//��result���������Ĵ���_max����
		 resultCount = 0;//������������㣬���¸�дresult
		 for (; 0 < n; --n)
			 result[n - 1] = 1;
		++_count;//Ԫ������������+1
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