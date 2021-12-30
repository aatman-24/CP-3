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

PRIME FACTORIZATION


HERE I FIRST GET ALL PRIME FACTOR AND STORED INTO SET BCZ IT STORE ONLY UNIQUE VALUE IN SORTED ORDER.

AND IF MORE THAN ONE PRIME FACTOR INTO SET I GOT LAST ONE.

*/

vll primes;
vll arr;
ll _sieve_size;

set<ll> primeFactor(int N) {
	set<ll> result;
	while(N != 1) {
		result.insert(arr[N]);
		N /= arr[N];
	}
	return result;
}

void sieve(ll ub) {
	_sieve_size = ub + 1;
	arr.assign(_sieve_size,0);

	for(int i = 0; i < _sieve_size; i++) 
		arr[i] = i;

	for(ll i = 2; i < _sieve_size; i++) {
		if(arr[i] == i){
			for(ll j = i*i; j < _sieve_size; j+=i) arr[j] = i;
			primes.push_back(i);
		}
			
	}
}


int main()
{

	int _sieve_size = 10000000;
	sieve(10000000);

	ll N,LDP=1,PI,PN;
	while(cin >> N) {

		if(!N) break;
		N = abs(N);
		set<ll> result;
		if(N < _sieve_size) result = primeFactor(N);
		else {
			
			PI = 0; PN = primes[PI];
			while(N > PN * PN) {
				PN = primes[PI];
				while(N % PN == 0) {N /= PN; result.insert(PN);}
				PI++;
			}
			if(N > 1) result.insert(N);
		}

		if(result.size() > 1) {
			auto it = result.end();
			it--;
			cout << *it << endl;
		}
		else {
			cout << "-1" << endl;
		}
		

	}
    return 0;
}

