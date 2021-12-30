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

Question NO : UVa 10176	- Ocean Deep! Make It Shallow!

Question : Given Binary number is divisible by MOD or not.

Topic : powerMod() + sumMod concept.

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

	ll MOD = 131071;
	string number = "";
	ll total;
	char char_tmp;
	while(cin >> char_tmp) {
		if(char_tmp != '#') {
			number += char_tmp;
		}
		else {
			total = 0;
			int sizeOfNumber = (int)number.size();
			for(int i = 0 ; i < sizeOfNumber; i++) {
				if(number[i] == '1')
					total = (total % MOD + powerMod(2, sizeOfNumber - i - 1,MOD)) % MOD;
			}

			if(total % MOD == 0) cout << "YES" << endl;
			else cout << "NO" << endl;

			number = "";
		}
	}


    return 0;
}

