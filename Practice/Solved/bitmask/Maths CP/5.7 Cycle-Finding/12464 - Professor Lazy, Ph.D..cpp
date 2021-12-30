#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(ll i = 0; i < n; i++)
#define REP1(i,n) for(ll i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;

#define F first
#define S second
#define PB push_back
// #define endl '\n'

typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,ll> mci;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef map<ll,ll> mii;


/*
==============================> Apporach <=============================================

Question : 	12464 - Professor Lazy, Ph.D.
Topic : pattern, cycle-finding
Approach : a -> b -> 1+b/a -> (1+a+b)/(a.b) -> 1+a/b

this type of pattern is occur

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


ll alpha1, beta1, N;
vi arr;

ll f(ll index) {
	if(index + 1 >= (ll)arr.size()) arr.push_back((1+arr[index])/arr[index-1]);
	return index+1;
}

void printARR() {
	REP(i,(int)arr.size()) cout << arr[i] << ' ';
	cout << endl;
}

ii floydCycleFinding(ll index0) {


	ll fast = f(index0), slow = f(f(index0));

	printARR();
	// set the initial gap
	while(arr[fast] != arr[slow]) {fast = f(fast); slow = f(f(slow));}

	// get the mu
	ll mu = 0; slow = index0;
	while(arr[fast] != arr[slow]) {fast = f(fast); slow = f(slow);}

	// get the lambda
	ll lambda = 1; slow = f(fast);
	while(arr[fast] != arr[slow]) {slow = f(slow); lambda++;}

	return ii(mu,lambda);
}


int main()
{

	int a,b;
    long long n;
     
    while(true){
        scanf("%d %d %lld",&a,&b,&n);
         
        if(a == 0) break;
         
        n %= 5;

        if(n == 0) cout << a << endl;
        if(n == 1) cout << b << endl;
        if(n == 2) cout << (1 + b) / a << endl;
        if(n == 3) cout << (1 + a + b) / a / b << endl;
        if(n == 4) cout << (1 + a) / b << endl; 
        
    }
     
}

