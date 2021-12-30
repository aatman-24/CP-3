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

Question : Coin Change
Topic : DP - knapsack unbounded (pattern)
https://practice.geeksforgeeks.org/problems/coin-change2448/1#

*/


// Count Number of maximum number of ways to(or subset) make Total cent using coins. {1,1,1,1} {2,2} -> 4 with {1,2} denomintaor.
// TC = Total Cent, n = Number of Denominator
int count(int S[], int n, int TC) {

    int dp[n+1][TC+1];
    memset(dp, 0, sizeof(dp));

    // we can pay 0 cent using any number of coin> 0. 
    for(int i = 1; i <= m; i++) dp[i][0]= 1; 

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <=n; j++) {
            if(S[i-1] <= j) {
                dp[i][j] = (dp[i][j-S[i-1]]) + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[m][n];

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

