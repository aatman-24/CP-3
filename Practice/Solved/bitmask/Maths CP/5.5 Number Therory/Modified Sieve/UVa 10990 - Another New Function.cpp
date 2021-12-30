#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define REP2(i,n) for(int i = 2; i <= n; i++)
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

Question NO : UVa 10990	- Another New Function

Question : We have to count for given N -> while(EularPhi(N) != 1) {N = EularPhi(N); cnt++}

example....
ϕ(13) = 12 . . . step1
ϕ(12) = 4 . . . step2
ϕ(4) = 2 . . . step3
ϕ(2) = 1 . . . step4

ans = 4;

Topic : eular phi, dp(somewhat)

NOTE : Here I not used proper dp but somewhat using vector arr. Still I am getting worst case timing 2.34555 sec.
*/


ll _sieve_size, PI, PN;
bitset<1000007> bt;
vl primes;
int EularPhiARR[2000001];
vi EularPhiDepthArr(2000001, 0);

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


ll EularPhi(ll N) {
	ll ans = N;
	PI = 0; PN = primes[PI];
	while(N >= PN * PN) {
		if(N % PN == 0) ans -= (ans / PN);
		while(N % PN == 0) N /= PN;
		PI++; PN = primes[PI];
	}
	if(N > 1) ans -= (ans / N);
	return ans;
}


ll getEularPhiDepth(ll N) {
	ll ans = N;
	int cnt = 0;
	while(ans != 1) {
		if(EularPhiDepthArr[ans] != 0) {
			cnt += EularPhiDepthArr[ans];
			return cnt;
		}
		ans = EularPhi(ans);
		cnt++;
	}
	return cnt;
}



int main()
{

	sieve(1000007);

	REP1(i, 2000000) {
		EularPhiARR[i] = EularPhi(i);
	}

	REP2(i, 2000000) {
		EularPhiDepthArr[i] = getEularPhiDepth(i);
	}


	ll N,M,sum_tmp;
	int t; cin >> t;
	while(t--) {
		cin >> M >> N;
		sum_tmp = 0;
		for(ll i = M ; i <= N ; i++) {
			sum_tmp += EularPhiDepthArr[i];
		}
		cout << sum_tmp << endl;
	}

    return 0;
}

