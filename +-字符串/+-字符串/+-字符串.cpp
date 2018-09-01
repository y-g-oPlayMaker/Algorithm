#include<iostream>
#include<string>
using namespace std;
string S1;
string S2;
int cnt=0;
int result(string S1, string S2);
int main()
{
	while (cin >> S1 >> S2)
	{
		if (S1.size() == S2.size())
			result(S1,S2);
		else cout << "-1" << endl;
		cnt = 0;
	}
	return 0;
}


int result(string S1, string S2)
{
	for (unsigned i = 0; i < S1.size(); ++i)
	{
		unsigned j = i;
		if (S1[i] != S2[i])
		{
			do
			{
				if (j == S1.size() - 1)
				{
					cout << "-1" << endl;
					return 0;
				}
				++j;
			} while (S1[j] != S2[i]);

			if (S1[j] == '+')
			{
				S1[j] = '-';
			}
			else
			{
				S1[j] = '+';
			}
			S1[i] = S2[i];
			cnt += j - i;
		}	
	}
	cout << cnt << endl;
}