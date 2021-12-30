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

Question : 10139 Factovisors
Topic : Number Therory

This is very time bound question here for Divisor D we we get all prime factor one by one
and every time we check power of this prime factor into N!. If any time power of prime into N! is less
we directly return false .

*/


vll primes;
bitset<10000000> bt;
ll _sieve_size,PI,PN,cnt;


void sieve(ll ub) {
	_sieve_size = ub + 1;
	bt.set(); bt[0]=bt[1]=0;
	for(ll i = 2; i < _sieve_size; i++) {
		if(bt[i]) {
			for(ll j = i*i; j < _sieve_size; j+=i) bt[i] = 0;
			primes.push_back(i);
		}
			
	}
}



//	It return true power of prime factor P into N! is greater or equal to N else false;
ll checkFactorIntoN(ll N, ll P, ll cnt) {
	if(P <= 1) return true;
	ll res = 0;
	for(ll i = P; i <= N ; i *= P) {
		res += (N / i);
	}
	return res >= cnt;
}



//	This Fucntion Check Whether the N! is Divisible by D or Not.
bool primeFactor(ll N, ll D) {
	PI = 0; PN = primes[PI];
	while(D >= PN * PN) {
		if(D % PN == 0) {
			cnt = 0;
			while(D % PN == 0) {D /= PN; cnt++;}
			if(!checkFactorIntoN(N, PN, cnt)) return false;
		}
		PI++; PN = primes[PI];
	}

	if(D > 0) {
		if(!checkFactorIntoN(N, D, 1)) return false;
	}

	return true;
}

int main()
{

	sieve(1000000);
	ll N,M;
	bool flag;

	while(cin >> N >> M) {

		flag = false;
		if(M != 0){
			flag = primeFactor(N,M);
		}
		else flag = true;

		if(flag) cout << M << " divides " << N << '!' << endl;
			else cout << M << " does not divide " << N << '!' << endl;

	}

    return 0;
}

