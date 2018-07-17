#include<iostream>
#include<vector>
using namespace std;
int k;
int _count = 0;
vector<int> x, y;
vector<vector<int>> resultX;
vector<vector<int>> resultY;
int main()
{
	while (cin >> k)
	{
		for (double i = k + 1; i <= 2 * k; i++)
		{
			if (int(i*k / (i - k)) == i * k / (i - k))
			{
				x.push_back(i);
				y.push_back((i*k) / (i - k));
			}
		}
		resultX.push_back(x);
		resultY.push_back(y);
		_count++;

	}

	for (unsigned i = 0; i < resultX.size(); ++i)
	{
		cout << resultX.size() << endl;
		for (unsigned j = 0; j < resultX[i].size(); ++j)
		{
			cout << "1/" << k << "=" << "1/" << resultY[i][j] << "+" << "1/" << resultX[i][j] << endl;
		}
	}
	system("pause");
	return 0;
}