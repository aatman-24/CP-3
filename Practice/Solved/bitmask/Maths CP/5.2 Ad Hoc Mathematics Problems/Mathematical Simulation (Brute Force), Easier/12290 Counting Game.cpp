#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool clap_or_not(int a)
{
	if(a % 7 == 0) return true;
	while(a)
	{
		if(a % 10 == 7) return true;
		a /= 10;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n,m,k;
	while(cin >> n >> m >> k)
	{
		if(!(n || m || k)) break;
		int i = 1;
		int increment_by = 1;
		int count = 1;
		while(k)
		{

			if(clap_or_not(count) && i == m) k--;
			if(k)count++;
			if(i == n) increment_by = -1;
			if(i == 1) increment_by = 1;
			i += increment_by;
		}

		cout << count << endl;
	}



	return 0;
}

