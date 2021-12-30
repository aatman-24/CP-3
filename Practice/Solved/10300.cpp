#include <bits/stdc++.h>
// #include <iostream>
#define ll long long

using namespace std;

int recursive_sum(int n)
{
	if ((n >= 0) & (n<=9))
	{
		return n;
	}
	else
	{
		int sum = 0;
		while (n != 0)
		{
			sum += (n % 10);
			n = n/10;
		}
		return recursive_sum(sum);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t = 1;
	while(t--)
	{
		int n;
		cin >> n;
		if (n == 0)
		{
			break;
		}
		else
		{
			cout << recursive_sum(n) << endl;
		}
	}
	return 0;
}

