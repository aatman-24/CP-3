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


typedef vector<ll> vl;
typedef map<ll,ll> mll;
typedef vector<pair<ll,ll>> vpll;

/*
==============================> Apporach <=============================================

Question NO : UVa 11728 - Alternate Task 
Question : Given S found whose sum divisor is. reverse of(SumDiv(N))
Topic : sumDiv(N), sieve, prime factor
*/


ll _sieve_size, PI, PN;
bitset<1000007> bt;
vl primes;



void sieve(ll ub) {
	_sieve_size = ub + 1;
	bt.set();
	bt[0] = bt[1] = 0;
	for(ll i = 2; i < _sieve_size; i++) {
		if(bt[i]) {
			for(ll j = i * i; j < _sieve_size; j+=i) bt[j] = 0;
			primes.push_back(i);
		}
	}
}


int numDiv(ll N) {
	int cnt,res = 1;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		cnt = 0;
		while(N % PN == 0) {N/=PN; cnt++;}
		res *= (cnt + 1);
		PI++; PN = primes[PI];
	}
	if(N > 1) res *= 2;
	return res;
}

ll power(ll base, ll n) {
	ll res = 1;
	while(n) {
		if(n % 2) res *= base;
		base *= base;
		n/=2;
	}
	return res;
}

int sumDiv(ll N) {
	int cnt, res = 1;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		cnt = 0;
		while(N % PN == 0) {N /= PN; cnt++;}
		if(cnt > 0){
			res = res * ((power(PN,cnt+1) - 1) / (PN-1));
		}
		PI++; PN = primes[PI];
	}
	if(N > 1) res = res * ((power(N,2) - 1 ) /(N-1));
	return res;
}


int main()
{

	sieve(1000007);

	mll res;
	for(ll i = 1; i < 10000; i++) {
		res[sumDiv(i)] = i;
	}

	int N,t;
	t = 0;
	while(cin >> N) {
		if(!N) break;

		cout << "Case " << ++t << ": ";
		if(res.find(N) == res.end()) cout << "-1" << endl;
		else cout << res[N] << endl;
	}

    return 0;
}

