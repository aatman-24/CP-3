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

Question NO : UVa 10212	- The Last Non-zero Digit.

Question : find -> N permutation M 
Topic : muliplication modulo used.
NOTE : for finding the non-last digit zero. every sted if last digit is occured in ans we must tune it.
MOD = 10^9 is used. Int range.

*/


int main()
{

	ll N, M;
	ll MOD = 1000000000;

	while(cin >> N >> M) {
		ll ans = 1;
		for(ll i = N; i >= N - M + 1; i--) {    // 10 P 5 = 10 * 9 * 8 * 6 * 5 * 4 * 3 * 2 * 1 / 5 * 4 * 3 * 2 * 1
			ans *= i;							// 10 P 5 = 10 9 8 7 6
			while(ans % 10 == 0) {
				ans /= 10;
			}
			ans = ans % MOD;
		}
		cout << ans % 10 << endl;
	}	
    return 0;
}

