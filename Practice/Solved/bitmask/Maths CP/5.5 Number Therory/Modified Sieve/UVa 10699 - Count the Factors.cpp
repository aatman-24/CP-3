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

Question NO : UVa 10699 - Count the Factors
Question : Count the all PF for given N.
Topic : numDiffPF(N) is used.
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

int numDifPf(ll N) {
	int diffPF = 0;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		if(N % PN == 0) diffPF++;
		while(N % PN == 0) N /= PN;
		PI++; PN = primes[PI];
	}
	if(N > 1) diffPF++;
	return diffPF;
}


int main()
{

	sieve(1000007);

	int N,t;
	t = 0;
	while(cin >> N) {
		if(!N) break;
		cout << N << " : " << numDifPf(N) << endl; 
	}

    return 0;
}

