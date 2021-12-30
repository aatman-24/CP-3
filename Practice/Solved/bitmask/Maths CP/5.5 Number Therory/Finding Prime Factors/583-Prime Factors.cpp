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



*/

vll primes;
vll arr;
ll _sieve_size;


ll power(ll base, ll n) {
	ll res = 1;
	while(n) {
		if(n % 2) res = res * base;
		base = base * base;
		n /= 2;
	}
	return res;
}

vi primeFactor(int N) {
	vi result;
	while(N != 1) {
		result.push_back(arr[N]);
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

	// cout << primes[0] << endl;

	bool POS;
	ll N, PI, PN, tmpN;
	while(cin >> N) {

		if(!N) break;
		POS = (abs(N) == N);
		N = abs(N);
		tmpN = N;

		vi result;
		if(N < _sieve_size) result = primeFactor(N);
		else {
			
			PI = 0; PN = primes[PI];

			while(N > PN * PN) {
				PN = primes[PI];
				while(N % PN == 0) {N /= PN; result.push_back(PN);}
				PI++;
			}
			if(N > 1) result.push_back(N);
		}

		// sort(result.begin(), result.end());

		if(POS){
			cout << tmpN << " = ";
			for(double i = 0; i < result.size(); i++) {
			if(i == 0) cout << result[i];
			else cout << " x " << result[i];
			}
		}
		else {
			cout << '-' << tmpN << " = " << "-1";
			for(double i = 0; i < result.size(); i++) {
				cout << " x " << result[i];
			}
		}

		cout << endl;

	}






	// mii re = primeFactor(N);
	// map<int,int>::reverse_iterator itr;
	// for(itr = re.rbegin(); itr != re.rend(); itr++) {
	// 	if(itr == re.rbegin()) cout << itr->first  << ' ' << itr->second;
	// 	else cout << ' ' << itr->first  << ' ' << itr->second ;
	// }
	// cout << endl;

    return 0;
}

