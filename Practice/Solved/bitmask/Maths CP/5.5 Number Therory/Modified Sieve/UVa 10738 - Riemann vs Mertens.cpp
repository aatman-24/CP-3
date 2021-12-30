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

Question NO : UVa 10738	- Riemann vs Mertens

Question : count as per requirements. M(N) = mu(1) + mu(2) + . . . + mu(N)
where mu(i) -> 
• mu(1) = 1, by definition;
• if N is not square free, mu(N) = 0;
• if N is square free and contains an even number of prime factors, mu(N) = 1;
• if N is square free and contains an odd number of prime factors, mu(N) = −1.

square free Num -> contain only 1 power of prime factor.

Topic : modified sieve numDifPf(i) is used..
*/


ll _sieve_size, PI, PN;
bitset<1000007> bt;
vl primes;
int arr[1000001], summation[1000001];


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


int getMU(ll N) {
	if(N == 1) return 1;

	int mu = 1;
	mll storage;
	PI = 0; PN = primes[PI];

	while(N >= PN * PN) {
		if(N % PN == 0) {storage[PN] = 1; N/=PN;}
		while(N % PN == 0) {
			N /= PN;
			storage[PN]++;
			mu = 0;
		}
		PI++; PN = primes[PI];
	}

	if(N > 1) storage[N] = 1;
	if(mu) {
		if(storage.size() % 2) return -1;
		return 1;
	}
	return mu;
}

int main()
{

	sieve(1000007);
	REP1(i,1000000) {arr[i] = getMU(i);}

	summation[1] = 1;
	for(int i = 2; i <= 1000000; i++) {
		summation[i] = arr[i] + summation[i-1];
	}

	int N;
	while(cin >> N) {
		if(!N) break;
		printf("%8d%8d%8d\n",N, arr[N], summation[N]);
	}


    return 0;
}

