#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define REP2(i,n) for(int i = 2; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


typedef vector<ll> vl;
typedef map<ll,ll> mll;
typedef vector<pair<ll,ll>> vpll;

/*
==============================> Apporach <=============================================

Question NO : UVa 374 - Big Mod

Question : R := B^P mod M


Topic : powerMod(base, n, mod)


*/


ll powerMod(ll base, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n % 2) res = ((res % mod) * (base % mod) % mod);
		base = ((base % mod) * (base % mod) % mod);
		n /= 2;
	}
	return res % mod;
}



int main()
{
	ll B, P, M;
	while(cin >> B >> P >> M) {
		cout << powerMod(B,P,M) << endl;
	}
    return 0;
}

