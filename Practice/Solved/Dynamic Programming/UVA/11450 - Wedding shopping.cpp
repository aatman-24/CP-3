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

Question : 11450 - Wedding shopping
Topic : DP(knapsack - variants) (extended knapsack)


*/
int money, N_G;
int price[25][25];
int t[25][210];

int maxVal(int G, int M) {

	if(G == 0) return t[G][M] = money - M;
	if(M < 0) return t[G][M] = INT_MIN;

	if(t[G][M] != -1) return t[G][M];

	int mn = -1;

	for(int item = 1; item <= price[G-1][0]; item++) {
		if(M >= price[G-1][item])
			mn = max(mn, maxVal(G-1, M - price[G-1][item]));
	}

	return t[G][M] = mn;
}



int main() {

	int test; cin >> test;
	while(test--) {

		memset(t, -1, sizeof(t));

		cin >> money >> N_G;
		for(int cn = 0; cn < N_G; cn++) {
			cin >> price[cn][0];
			for(int k = 1; k <= price[cn][0]; k++) cin >> price[cn][k];
		}

		int ans = maxVal(N_G, money);
		if(ans >= 0) cout << ans << endl;
		else cout << "no solution" << endl; 

	}


	
}