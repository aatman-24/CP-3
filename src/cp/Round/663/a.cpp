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
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int i=1;
		while (i != n)
		{
			cout << i << " ";
			i++;
		}
		cout << n << endl;
	}
	return 0;		
}