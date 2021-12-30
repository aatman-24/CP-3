#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;

#define F first
#define S second
#define PB push_back
#define endl '\n'

typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;


/*
==============================> Apporach <=============================================

Question : 	Uva 11634-Generate random numbers
Topic : cycle-finding, floydCycleFinding, Number Therory
Approach : Here we have to find how many differnt number is generated.

So ans is mu + lambda (that is differnt number) we have to add mu bcz it is differnt number and after the
lambda length is same number.

*/

ll power(ll base, ll n) {
	ll res = 1 ;
	while(n) {
		if(n % 2) res *= base;
		base *= base;
		n /= 2;
	}
	return res;

}


ll a,b,N;
ll cnt, num, i;

ll f(ll a) {
	return  (a * a / 100) % 10000; // get middle four digit of a * a
}

ii floydCycleFinding(ll x0) {

	ll tortoise = f(x0), hare = f(f(x0));

	// ll tortoise = x0, hare = x0;

	// step1 set the gap
	while(tortoise != hare) {tortoise = f(tortoise); hare = f(f(hare));}

	// step2 find mu
	ll mu = 0; hare = x0;
	while(tortoise != hare) {tortoise = f(tortoise); hare = f(hare); mu++;}

	//step 3 find lambda
	ll lambda = 1; hare = f(tortoise);
	while(tortoise != hare) {hare = f(hare); lambda++;}


	return ii(mu,lambda);

}

int main()
{

	while(cin >> N) {
		if(!N) break;
		ii res_par = floydCycleFinding(N);
		cout << res_par.F + res_par.S << endl;
	} 
}

