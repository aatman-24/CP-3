#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef vector<ll> vl;
typedef map<ll,ll> mll;
typedef vector<mll> vmll;


/*
==============================> Apporach <=============================================

Question : 10680 - LCM (TLE)
Topic : PRIME FACTORIAZATION

I GOT TLE.

APPORACH IS THAT FOR GIVEN N
TO FIND LCM[1..N] YOU NEED TO FIND ALL PRIME NUMBER POWER UNTIL N.
WHICH IS EQUAL TO LCM[1..N].


*/

ll MAX_SIZE = 1000007;
bitset<1000007> bt;
vl primes;

ll _sieve_size, PI, PN;


void sieve(ll ub) {
	_sieve_size = ub + 1;
	bt.set();
	bt[0] =  bt[1] = 1;
	for(ll i = 2; i < _sieve_size ; i++) {
		if(bt[i]){
			for(ll j = i*i; j < _sieve_size; j+=i) bt[j] = 0;
			primes.push_back(i);
		}
	}
}


ll power(ll base, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n % 2) res = (res % mod) * (base % mod) % mod;
		base = (base % mod) * (base % mod) % mod;
		n /=2 ;
	}
	return res % mod;
}


mll getLCM(ll N){
	mll res;
	ll tmpN = N;
	PI = 0; PN = primes[PI];
	while(tmpN >= PN) {
		res[PN] = 0;
		while(tmpN/PN > 0) {tmpN /= PN; res[PN]++;}
		PI++; PN = primes[PI];
		tmpN = N;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	sieve(1000007);

	ll N;
	int cnt = 0;
	while(cin >> N && cnt < 1000) {

		if(N == 0) break;
		if(N == 1) {cout << '1' << endl; continue;}

		ll LCM = 1;

		mll factorOFN = getLCM(N);
		if(factorOFN.find(2) != factorOFN.end() && factorOFN.find(5) != factorOFN.end()) {
			ll X = min(factorOFN[2],factorOFN[5]);
			factorOFN[2] -= X;
			factorOFN[5] -= X;
		}

		for(auto i : factorOFN) {
			LCM = (LCM % 10) * (power(i.first, i.second, 10));
		}
		cout << LCM % 10  << endl;
		cnt++;
	}

    return 0;
}

