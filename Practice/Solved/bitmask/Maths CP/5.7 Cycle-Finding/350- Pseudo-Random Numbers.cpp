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

Question : 350	Pseudo-Random Numbers
Topic : Cycle Finding, floydCyclefinding-Algo
O(mu + lambda)

*/



int Z,I,M,L;

int f(int x) {
	return (Z*x+I) % M;
}
	


ii floydCyclefinding(int x0) {
	// 1st part : find k*lambda(gap is generated)   torotoise -> 1X and hare -> 2X 
	int torotoise = f(x0), hare = f(f(x0));
	while(torotoise != hare) {torotoise = f(torotoise); hare = f(f(hare));}

	// 2nd part: finding mu
	int mu = 0; hare = x0;
	while(torotoise != hare) {torotoise = f(torotoise); hare = f(hare); mu++;}

	// 3rd part: finding lambda
	int lambda = 1; hare = f(torotoise);
	while(torotoise != hare) {hare = f(hare); lambda++;}

	return ii(mu,lambda);
}




int main()
{
	int t = 0;
 	while(cin >> Z >> I >> M >> L) {
 		if(!(Z && I && M && L)) break;
 		int lambda = floydCyclefinding(L).second;

 		cout << "Case " << ++t << ": " << lambda << endl;

 	}

    return 0;
}

