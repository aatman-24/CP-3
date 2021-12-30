#include <bits/stdc++.h>
#define ll long long
using namespace std;

void show(int a[],int n)
{
	for (int i=0;i<n;i++)
	{
		cout << a[i] << "   ";
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
	int t;
	cin >> t ;
	while(t--)
	{
		int n;
		long long int minA,minB;
		cin >> n;
		int a[n],b[n];
		minA  = 10000000000000;
		minB = 100000000000000;
		int temp;
		for (int i=0;i<n;i++)
		{
			cin >> temp;
			if (temp < minA)
			{
				minA = temp;
			}
			a[i] = temp;
		}
		for (int i=0;i<n;i++)
		{
			cin >> temp;
			if (temp < minB)
			{
				minB = temp;
			}
			b[i] = temp;
		}
	// Real code start form here.
		int c = 0;
		long long cost=0;
		while (c != n)
		{
			cost += max((a[c]-minA),(b[c]-minB));
			c++;
		}
	cout << cost << endl;
	}
	return 0;
}	