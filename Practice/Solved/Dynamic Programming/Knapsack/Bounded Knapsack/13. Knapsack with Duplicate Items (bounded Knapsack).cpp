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

Question : 
Topic : 

*/

int boundedKnapSack(int N, int W, int val[], int wt[])
{
    int dp[N+1][W+1];
    memset(dp, 0, sizeof(dp));

    for(int i = 1; i <= N; i++) {
    	for(int j = 1; j <= W; j++) {
    		if(wt[i-1] <= j) {
    			dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);  // dp[i][j - wt[i-1]]
    		}
    		else {
    			dp[i][j] = dp[i-1][j];
    		}
    	}
    }

    return dp[N][W];

}


int main()
{

	int t;
	cin >> t;
	while(t--) {
		int N, W;
		cin >> N >> W;
		int wt[N], val[N];
		for(int i = 0; i < N; i++) cin >> val[i];
		for(int i = 0; i < N; i++) cin >> wt[i];

		cout << boundedKnapSack(N, W, val, wt) << endl;

	}
	return 0;

}

