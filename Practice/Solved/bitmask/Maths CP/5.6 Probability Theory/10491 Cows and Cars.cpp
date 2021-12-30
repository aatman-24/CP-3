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

Question NO : UVa 10491 - Cows and Cars

Question :  
Topic : probablity closed form formula.
	(NCOWS / (NCOWS+NCARS)) * (NCARS / (NCARS+NCOWS-NSHOW-1)) + (NCARS / (NCARS+NCOWS)) * ((NCARS-1) / (NCARS+NCOWS-NSHOW-1))

*/



int main()
{

	double NCOWS, NCARS, NSHOW;
	while(cin >> NCOWS >> NCARS >> NSHOW) {
		double total = NCOWS + NCARS;
		double res = (NCOWS /  total) * ((NCARS) / (total - NSHOW - 1));
		res += (NCARS/ total) * ((NCARS-1) / (total - NSHOW - 1));
		printf("%0.5f\n", res);
	}


	
    return 0;
}

