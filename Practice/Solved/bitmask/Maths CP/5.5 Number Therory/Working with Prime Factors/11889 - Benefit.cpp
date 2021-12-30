#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef vector<int> vi;
typedef map<int,int> mii;
typedef vector<mii> vmii;


/*
==============================> Apporach <=============================================

Question : 11889 - Benefit
Topic : PRIME FACTORIZATION 

Given A,C -> LCM(A,B) = C

C contain max term from the A and B.

constraints :

- C must contain all the factor of A and also power of factor is greater than A.
- C contain max power of factor is either from A or B.
	1) If from A than to be minimum B, Bth factor is -> factor^(0) -> 1
	2) If A not contain that much power then It must be from B, factor of B is -> factor^(N_power) 
*/

ll _sieve_size, PI, PN;
vi primes;
bitset<10000000> bt;
int MAX_SIZE = 1000000;


void sieve(ll ub) {
	_sieve_size = ub + 1;
	bt.set();
	bt[0] = bt[1] = 0;
	for(ll i = 2; i < _sieve_size ; i++) {
		if(bt[i]) {
			for(ll j = i * i; j < _sieve_size ; j += i) bt[j] = 0;
			primes.push_back(i);
		}
	}
}


mii getPrimeFactor(ll N) {
	mii result;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		if(N % PN == 0) result[PN] = 0;
			while(N % PN == 0) {N /= PN; result[PN]++;}
		PI++; PN = primes[PI];
	}
	if(N > 1) result[N] = 1;
	return result;
}


int power(int base, int n) {

	int res = 1;
	while(n) {
		if(n % 2) res *= base;
		base *= base;
		n /= 2;
	}
	return res;

}


int getB(mii a, mii b) {
	int N = 1;
	for(auto i : a) {
		if(b.find(i.first) == b.end() || i.second > b[i.first]) {return -1;}
	}

	for(auto i : b) {
		if(a.find(i.first) == a.end()) {
			N *= power(i.first, i.second);
		}
		else {
			if(i.second == a[i.first]) N *= 1;  
			else N *= power(i.first, i.second);
		} 
	}
	return N;
}





int main()
{


	sieve(10000000);

	int A, C;
	int t ; cin >> t;
	while(t--) {
		cin >> A >> C;
		mii factorA = getPrimeFactor(A);
		mii factorC = getPrimeFactor(C);
		int K  =  getB(factorA, factorC);
		if(K == -1) cout << "NO SOLUTION" << endl;
		else cout << K << endl;
	}
    return 0;
}

