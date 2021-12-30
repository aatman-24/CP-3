#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


ll pow(ll base,ll n)
{
	if(n == 0) return 1;
	else{
		ll ans = pow(base,n/2);
		ans *= ans;
		if(n % 2 != 0) ans *= base;
		return ans;
	}
}



ll length(ll x, ll base)
{
	int cn = 0;
	while(x)
	{
		x /= base;
		cn++;
	}
	return cn;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	
	ll base,l_d,y;
	while(cin >> base >> l_d >> y)
	{
		ll x = 1;
		while(1)
		{
			if((base*x + l_d)*y == (pow(base,length(x,base)) * l_d + x))
			{
				break;
			}
			x++;
		}

		cout << (base*x + l_d) << '|' <<  (pow(base,length(x,base)) * l_d + x)<< endl;
	}



	return 0;
}

