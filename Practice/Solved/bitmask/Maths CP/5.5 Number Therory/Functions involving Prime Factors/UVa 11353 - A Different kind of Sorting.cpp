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

Question NO : UVa 11353 - A Different kind of Sorting
Question : sort based on total num  of PF.
Topic : totalNumPF(N), sieve, prime factor
sort based on totalNumPf().
*/


ll _sieve_size, PI, PN;
bitset<1000007> bt;
vl primes;
vpll res;

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

int totalNumPF(ll N) {
	int totalPF = 0;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		while(N % PN == 0) {N /= PN; totalPF++;}
		PI++; PN = primes[PI];
	}
	if(N > 1) totalPF++;
	return totalPF;
}


bool sort_fun(pair<ll,ll> &p1, pair<ll,ll> &p2) {
	if(p1.second < p2.second) return true;
	if(p1.second == p2.second  && p1.first < p2.first) return true;
	return false;
}



int main()
{
	ll MAX_SIZE = 2000001;
	sieve(1000007);

	for(ll i = 1 ; i < MAX_SIZE; i++) {
		res.push_back({i,totalNumPF(i)});
	}


	sort(res.begin(), res.end(), sort_fun);

	int N;
	int t; t = 0;
	while(cin >> N) {
		if(!N) break;		
		cout << "Case "  << ++t << ": " << res[N-1].first << endl; 
	}


    return 0;
}

