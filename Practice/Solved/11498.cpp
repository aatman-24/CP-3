#include <bits/stdc++.h>
#define ll long long

using namespace std;

// 11498
void show(vector<int> &v)
{
	for (double i=0;i<v.size();i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}	




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	while (cin)
	{
		int div_x,div_y,n;
		cin >> n;
		cin >> div_x >> div_y;
		for (int i=0;i<n;i++)
		{
			int px,py;
			cin >> px >> py;
			if ((px == div_x) | (py == div_y))
			{
				cout << "divisa" << endl; 
			}
			else if ((px < div_x) & (py < div_y))
			{
				cout << "SO" << endl;
			}
			else if ((px < div_x) & (py > div_y))
			{
				cout << "NO" << endl;
			}
			else if ((px > div_x) & (py > div_y))
			{
				cout << "NE" << endl;
			}
			else if ((px > div_x) & (py < div_y))
			{
				cout << "SE" << endl;
			}
		}

	}
	return 0;		
}

