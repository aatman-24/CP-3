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

Question NO : UVa 11029	- Leading and Trailing

Question : find first three and last digit of N^K. (where n and k is high)

Topic : powerMod() - last three digit + logarithm to find first three digit concept.

*/


// FIRST DIGIT OF N -> O(log(N)).
// digits = log(N); // -> which return 10^digits-1 (if we represent the N into 10^digits form then)
// first_digit = (int)(N/ power(10,digits))


// SAME CONCEPT IS USED HERE,

// GIVEN X = N^K.

// now we represent the x into the 10^Y form where Y is decimal number(abc--.xyz--) (123.008) something like that.


// N^K = 10^Y ----- (1).

// take both side log10

// K * log10(N) = Y ---- (2) (so we got y from here). (which is in above format (abc--.xyz--))

// we have 10^(abc--.xyz--) 

// 10^abc-- + 10^.xyz--

// 10^abc-- -> represent the length of the result or how many digits in the form (100000) like that.
// 10^.xyz-- -> which is actual digit in result (1.234566) or (123.556) like something

// which result is 100000 + 123.556 -> 223000.556 result.

// but we need only first M digits which we got from easily here 10^.xyz--

// first M digits = 10^(.xyz-- + M - 1) 

// M - 1 bcz 0 based index used. 10^0 give 1 digit.  10^1 give 2 digit and 10^2 give three digit (100).










ll powerMod(ll base, ll n, ll mod) {
	ll res = 1;
	while(n) {
		if(n % 2) res = ((res % mod) * (base % mod) % mod);
		base = ((base % mod) * (base % mod) % mod);
		n /= 2;
	}
	return res % mod;
}


ll getLastMDigit(int base, int K, int M) {
	int MOD = pow(10,M);
	return powerMod(base, K, MOD);
}	


ll getMFirstDigit(int N, int K, int M) {
	double y = (double)K * log10(N*1.0);
	y -= (int)y;
	ll res = (1LL) * pow(10.0,y+M-1);
	return res;
}


int main()
{

	int t; cin >> t;
	int N,K;
	while(t--) {
		cin >> N >> K;
		cout << getMFirstDigit(N, K, 3) << "...";

		int LASTMDIGIT = getLastMDigit(N, K, 3);
		if(LASTMDIGIT < 10) {
			cout << "00" << LASTMDIGIT << endl;
		} 
		else if (LASTMDIGIT < 100) {
			cout << '0' << LASTMDIGIT << endl;
		}
		else {
			cout << LASTMDIGIT << endl;
		}
		
	}	


    return 0;
}

