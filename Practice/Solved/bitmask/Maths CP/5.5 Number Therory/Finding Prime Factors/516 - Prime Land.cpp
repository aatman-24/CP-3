#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl

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
int BASE_0 = 48;

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


ll power(ll base, ll n) {
	ll res = 1;
	while(n) {
		if(n % 2) res = res * base;
		base = base * base;
		n /= 2;
	}
	return res;
}


vi convertIntoNumber(string s) {
	vi result;
	int tmp = 0;
	int n = (int)s.size();
	for(int i = 0 ; i < n ; i++) {
		if(s[i] == ' ' & tmp > 0) {
			result.push_back(tmp);
			tmp = 0;
		}
		else {
			tmp = tmp * 10 + (s[i] - BASE_0);
		}
	}
	result.push_back(tmp);
	return result;
}

mii primeFactor(int N) {
	mii result;
	while(N != 1) {
		if(result.find(arr[N]) == result.end()) {
			result[arr[N]] = 1;
			N /= arr[N]; 
		} 
		else {result[arr[N]]++; N = N / arr[N];}
	}
	return result;
}


int main()
{

	sieve(32767);

	string s;
	while(getline(cin,s)) {

		if(s[0] == '0') break;
		vi result = convertIntoNumber(s);
		int N = 1;
		for(int i = 1 ; i < (int)result.size(); i+=2) {
			N *= (power(result[i-1],result[i]));
		}

		N = N - 1;
		mii re = primeFactor(N);
		map<int,int>::reverse_iterator itr;
		for(itr = re.rbegin(); itr != re.rend(); itr++) {
			if(itr == re.rbegin()) cout << itr->first  << ' ' << itr->second;
			else cout << ' ' << itr->first  << ' ' << itr->second ;
		}
		cout << endl;

	}
    return 0;
}

