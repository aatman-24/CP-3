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

Question : Maximize The Cut Segments
Topic : DP - knapsack unbounded (pattern)

*/


int maximizeTheCuts(int n, int x, int y, int z)
{

    int wt[3] = {x, y, z};

    int dp[4][n+1];
	memset(dp, 0, sizeof(dp));


	// Intialization 
	for(int j = 0; j <= n; j++) dp[0][j] = INT_MIN + 1000;
	for(int j = 1; j <= n; j++) dp[1][j] = (j % wt[0] == 0) ? j / wt[0] : INT_MIN + 1000;

	for(int i = 1; i <= 3; i++) {
    	for(int j = 1; j <= n; j++) {
    		if(wt[i-1] <= j) {
    			dp[i][j] = max(1 + dp[i][j-wt[i-1]], dp[i-1][j]);  // dp[i][j - wt[i-1]]
    		}
    		else {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    return max(dp[3][n], 0);
    
}

int rodCuttingMaxProfit(int n, int TL, int cut[], int profit[])
{


	int dp[n+1][TL+1];
	memset(dp, 0, sizeof(dp));

	// // Intialization 
	for(int j = 0; j <= n; j++) dp[0][j] = INT_MIN + 1000;
	// for(int j = 1; j <= n; j++) dp[1][j] = (j % wt[0] == 0) ? j % wt[0] : INT_MIN + 1000;

	for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= TL; j++) {
    		if(cut[i-1] <= j) {
    			dp[i][j] = max(profit[i-1] + dp[i][j-cut[i-1]], dp[i-1][j]);  // dp[i][j - wt[i-1]]
    		}
    		else {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    return max(dp[n][TL], 0);
    
}

int main()
{

	int t, n, N;
	cin >> t;
	while(t--) {

		cin >> n >> N;
		int cut[n], price[n];
		for(int i = 0; i < n; i++) cin >> cut[i];
		for(int i = 0; i < n; i++) cin >> price[i];

		cout << rodCuttingMaxProfit(n, N, cut, price) << endl;

	}
	return 0;

}

