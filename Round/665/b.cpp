#include <bits/stdc++.h>
#include <iostream>
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
		int a1,b1,c1,a2,b2,c2;
		int x,y;
		cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
			x = min(c1,b2);
			int deleted_value;
			if (b2 == 0) deleted_value = c1;
			else{
				if ((b1 - x) > 0)
				{
					deleted_value = b1 - x;
				}
				else
				{
					deleted_value = 0;
				}
			}
			y = c2 - deleted_value;
			if ((y < a1) || (b1 == 0) || (y == 0) || (y < 0))
			{
				y = 0;
			}
			else
			{	
				if ((b1 >= a1)) y = min(abs(b1-a1),y);
				else if (b1 == a1) y = y - b1;
				else  y = b1;
				
			}
		cout << 2*x - 2*y << endl;
	}
}