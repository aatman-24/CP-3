#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int t;
	cin >> t;
	while(t--)
	{
		string num;
		cin >> num;
		std::vector<int> v;
		double i = 0;
		while (i <= (num.length()-1))
		{
			if (num[i] == '0')
			{

				i++;
			}
			else
			{
				int a=0;
				while ((num[i] != '0') & (i <= (num.length()-1)))
				{
					a++;
					i++;
				}
				v.push_back(a);
			}
		}
		sort(v.begin(),v.end(), greater<int>());
		int alice=0;
		for (i=0;i<v.size();)
		{
			alice += v.at(i);
			i += 2;
		}
		cout << alice << endl;
	}
	return 0;
}

