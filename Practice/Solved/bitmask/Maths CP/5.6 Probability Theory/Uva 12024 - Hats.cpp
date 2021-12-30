#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Apporach <=============================================

Question : Uva 12024 - Hats
Topic : probablity, dearragment

- check the dearrangement therory.

for the de(5) = 5! - 5C1 * (4!) + 5C2 * (3!) - 5C3 * (2!) + 5C4 * (1!) - 5C5 * (0!)

*/



vll factorial;


ll combination(ll n, ll i) {

	if(i == 0 || i == n) return 1;

	ll res = factorial[n];
	res /= factorial[i];
	res /= factorial[n-i];

	return res;
}

int main()
{

	factorial.assign(14,0);
	factorial[0] = factorial[1] = 1;
	for(ll i = 2; i < 14; i++) {
		factorial[i] = factorial[i-1] * i; 
	}

	int t; cin >> t;
	int N;
	while(t--) {
		cin >> N;
		int tmp_N = N;
		ll res = factorial[N];
		int i = 1;
		while(i <= tmp_N) {
			if(i % 2) {
				res -= (combination(tmp_N, i) * factorial[N-i]);
			}
			else {
				res += (combination(tmp_N, i) * factorial[N-i]);
			}
			i++;
		}

		cout << res << '/'  << factorial[N] << endl;

	}


	// cout << combination(12,3) << endl;

    return 0;
}

