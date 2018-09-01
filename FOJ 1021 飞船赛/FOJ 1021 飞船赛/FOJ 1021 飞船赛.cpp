#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int n;
int cnt = 0
map<int, int> Y; //用map（key，value）结构来存储飞船的速度和初始名次

int main()
{
	cin >> n;
	//接收输入时直接接收每组的速度即可（因为名次时按升序排序），并存入Y（速度，名次）中；
	//时间为O（n*log2(N) ）
	int temp;
	for (int i = 0; i < n * 2; ++i)
	{
		cin >> temp;
		if (i % 2 != 0)                               
		{
			Y.insert(make_pair(temp, i / 2));
		}
	}
	//map会将其中的元素将key按hash的顺序自动排序（貌似本身并不在乎有序还是无需），所有元素按速度排序后会达到最后不再发生超车时的次序
	//因为超车只能发生在存在名次和速度差的车辆中，所以统计这辆车前初始名次大于它的个数就为他的超车次数
	//而将所有发生超车的车辆的超车次数相加即为总次数；这一步时间为O（n）；
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