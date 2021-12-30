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

Question : Minimum Number of Coins. 
Topic : DP - knapsack unbounded (pattern)
https://practice.geeksforgeeks.org/problems/number-of-coins1824/1
*/

// Count Number of min Coins needed for Total Cent.
// TC = Total Cent, n = Number of Denominator
int minCoins(int coins[], int n, int TC) {

	int dp[n+1][TC+1];
	memset(dp, 0, sizeof(dp));

	// if you have no coins (coin == 0) means you can't pay any cent Impossible. (It means you need INF number of coins to pay.) 
	for(int j = 0; j <= TC; j++) dp[0][j] = INT_MAX - 1;

	// Also need to initialize the 1st raw due to 0th raw = INF. if C = 4, coin = 2 -> 4/2 =  2
	// and if C = 4, coin = 3 you can not pay so INF.
	for(int j = 1; j <= TC; j++) dp[0][j] = (j % coins[0] == 0) ? j / coins[0] : INT_MAX - 1;


	// Here we set INT_MAX - 1 bcz (INT_MAX+1 -> -INT_MAX).

	for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= TC; j++) {
    		if(coins[i-1] <= j) {
    			dp[i][j] = min((1 + dp[i][j-coins[i-1]]) , dp[i-1][j]); // due that plus 1 we set INT_MAX - 1 .
    		}
    		else {
   				dp[i][j] = dp[i-1][j];
   			}
   		}
   	}

   	return (dp[n][TC] != INT_MAX - 1) ? dp[n][TC] : -1; // -1 as per problem description.

}


int main()
{

	int t, n, m;
	cin >> t;
	while(t--) {

		cin >> n >> m;
		int denominator[m];
		for(int i = 0; i < m; i++) cin >> denominator[i];
		cout << count(denominator, m, n) << endl;

	}
	return 0;

}

