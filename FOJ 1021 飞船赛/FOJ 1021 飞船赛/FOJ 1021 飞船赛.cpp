#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n;
int cnt = 0
map<int, int> Y; //��map��key��value���ṹ���洢�ɴ����ٶȺͳ�ʼ����

int main()
{
	cin >> n;
	//��������ʱֱ�ӽ���ÿ����ٶȼ��ɣ���Ϊ����ʱ���������򣩣�������Y���ٶȣ����Σ��У�
	//ʱ��ΪO��n*log2(N) ��
	int temp;
	for (int i = 0; i < n * 2; ++i)
	{
		cin >> temp;
		if (i % 2 != 0)                               
		{
			Y.insert(make_pair(temp, i / 2));
		}
	}
	//map�Ὣ���е�Ԫ�ؽ�key��hash��˳���Զ�����ò�Ʊ������ں����������裩������Ԫ�ذ��ٶ�������ﵽ����ٷ�������ʱ�Ĵ���
	//��Ϊ����ֻ�ܷ����ڴ������κ��ٶȲ�ĳ����У�����ͳ��������ǰ��ʼ���δ������ĸ�����Ϊ���ĳ�������
	//�������з��������ĳ����ĳ���������Ӽ�Ϊ�ܴ�������һ��ʱ��ΪO��n����
	for (map<int, int>::iterator it = ++Y.begin(); it != Y.end(); ++it)
	{
		for(map<int ,int>::iterator now=Y.begin();now!=it;++now)
			if (it->second<now->second)
			{
				cnt++;
			}
	}
	cout << cnt;
}