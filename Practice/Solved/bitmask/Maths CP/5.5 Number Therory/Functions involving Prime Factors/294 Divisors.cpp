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


/*
==============================> Apporach <=============================================

Question NO : 294-Divisors
Question : between [L,U] find number N which is has max number of divisor.
Topic : numDiv(N), sieve, prime factor
N = a^p1 b^p2 c^p3  (a, b, c is prime number using sieve)
res = (p1+1) * (p2+1) * (p3+1)
*/


ll _sieve_size, PI, PN;
bitset<10000007> bt;
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





int main()
{
	sieve(10000007);
	ll P,D,L,U;
	int t; cin >> t;
	while(t--) {
		cin >> L >> U;
		P = -1; D = 0;
		for(ll i = L ; i <= U ; i++) {
			int number_of_diviosr = numDiv(i);
			if(number_of_diviosr > D) {
				P = i;
				D = number_of_diviosr;
			}
		}

		cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << D << " divisors." << endl;
	}


    return 0;
}

