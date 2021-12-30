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
		int n,k;
		cin >> n >> k;
		if (k == 0)
		{
			if ((n % 2) == 0)
			{
				cout << "0" << endl;
			}
			else cout << abs(n-k) << endl;
		}
		else
		{
			cout << abs(n-k) << endl;
		}
	}
}