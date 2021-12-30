#include <bits/stdc++.h>
#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t = 2;
	while(t--)
	{
		int nPerson,nBudget,nHotel,nWeek;
		cin >> nPerson >> nBudget >> nHotel >> nWeek;
		cout << nPerson << " " << nBudget << " " << nHotel << " " << nWeek << endl;
		int sum = 10000000;
		while (nHotel--)
		{
			int h_price;
			cin >>h_price ;
			int t = nWeek;
			while(t--)
			{
				int bed_size;
				cin >> bed_size;
				if (nPerson <= bed_size)
				{
					if ((nPerson*h_price) <= min(sum,nBudget))
					{
						sum = nPerson*h_price;
					}
				}
			}
			// nHotel--;
		}
		if (sum <= nBudget)
		{
			cout << sum << '\n' ;
		}
		else
		{
			cout << "Stay HOme" << endl;
		}
		
	}
	return 0;
}

