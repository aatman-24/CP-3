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

typedef vector<vi> vvi;
typedef map<int,int> mii;

typedef vector<ll> vl;


/*
==============================> Apporach <=============================================

Question : 11395 - Sigma Function
Topic : sieve - prime Number 
SPC NOTES : if max boundary is greater than 10^7 once try to think is it sqrt(N) is under the 10^7 or not.
			yes than go for the primes number. 

Here we have to find given N -> How many number in [1..N] give sigma(N) is even.

sigma is ->  all prime factors sum.

sigma = (p1^(k+1) - 1/ p1 - 1) * (p2^(k+1) - 1/ p2 - 1) ... this equation 


factor power give below result

Number   power sum
even(2)  any   odd   (2^3) -> 2^4-1/2-1 -> 15 -> odd
odd 	odd    even  (3^3) -> 3^4-1/2 -> 40 -> even
odd     even    odd   (3^2) -> 3^3-1/2 -> 13 -> odd

odd * even -> even

so counting all even number -> N - (odd number)


How to count odd number ?

-> case-1 and case-3

1) any power of 2 means 2^k ,
2) odd number even power
3) multiple of above two number (reason odd*odd=odd)


combine both of this give -> 2^k * i^2 (where i is odd number)

rather than going upto N. we can go until sqrt(N) due to i^2. and check,
	while(2^K * I^2 <= N) cnt++; k++;  (for k = 1 to ....)

*/

ll power(ll base, ll n) {
	ll res = 1;
	while(n){
		if(n % 2) res *= base;
		base *= base;
		n /= 2;
	
	}
	return res;
}

int main()
{
	ll N, cnt;
	while(cin >> N) {
		if(!N) break;
		cnt = 0;
		for(ll i = 1; i <= sqrt(N) ; i++) {
			if(i % 2) {
				ll squareNum =  i * i;
				ll j = 0;
				while(power(2,j) * squareNum <= N) {
					cnt++;
					j++;
				}
			}
		}
		cout << N - cnt << endl;
	}
    return 0;
}


