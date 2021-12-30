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
https://practice.geeksforgeeks.org/problems/cutted-segments1642/1
*/


int maximizeTheCuts(int n, int x, int y, int z)
{

    int wt[3] = {x, y, z};

    int dp[4][n+1];
	memset(dp, 0, sizeof(dp));


	// Intialization 
	for(int j = 0; j <= n; j++) dp[0][j] = INT_MIN + 1000;
	for(int j = 1; j <= n; j++) dp[1][j] = (j % wt[0] == 0) ? j % wt[0] : INT_MIN + 1000;

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
int main()
{

	int t, x, y, z, n;
	cin >> t;
	while(t--) {
		
		cin >> n >> x >> y >> z;
		cout << maximizeTheCuts(n, x, y, z) << endl;

	}
	return 0;

}

