#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define F first 
#define S second

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

Question : 		357	Let Me Count The Ways
Topic : 0-1 Bounded Knapsack (Coin Change)

*/


ll t[6][30001];  
ll coins[5] = {1, 5, 10, 25, 50};

// 0.810 SEC
ll coinChange(int N, int C) {

	if(C == 0) return 1;
	if(N == 0) return 0;

	ll &best = t[N][C]; 
	if(best != -1) return t[N][C];

    if(coins[N-1] <= C) {
    	best = coinChange(N, C - coins[N-1]) + coinChange(N-1,C);
    }
    else {
    	best = coinChange(N-1, C);
    }
  	return best;
}

// 0.570 SEC
ll coinChange(int N, int C) {

	ll dp[N+1][C+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i <= N; i++) dp[i][0] = 1;

	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= C; j++) {
			if(coins[i-1] <= j) {
				dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j]; 
			}	
			else {
				dp[i][j] = dp[i-1][j];
			}
		}

	return dp[N][C];

}

int main()
{

	int C;
	while(cin >> C) {
		// memset(t, -1, sizeof(t));
		ll minCoinWay = coinChange(5, C);
		if(minCoinWay != 1) printf("There are %lld ways to produce %d cents change.\n", minCoinWay, C);
		else printf("There is only 1 way to produce %d cents change.\n",C);

	}
}