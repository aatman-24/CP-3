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

Question : 	11053	Flavius Josephus Reloaded
Topic : cycle-finding, floydCycleFinding, Number Therory

*/

ll a,b,N;
ll cnt;

int f(ll x) {
    int sol = ((a % N) * (((1LL * x) * x) % N)) % N;
    sol = (sol + b) % N;
    return sol;
}


ii floydCycleFinding(ll x0) {

	ll tortoise = f(x0), hare = f(f(x0));

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
		cin >> a >> b;
		ll died = floydCycleFinding(0).second;
		cout << N - died << endl;
	} 

    return 0;
}

