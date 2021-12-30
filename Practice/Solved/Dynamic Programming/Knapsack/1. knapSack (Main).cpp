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

// Top-Down Apporach
int knapSack(int W, int wt[], int val[], int n) 
{ 
    
    int dp[n+1][W+1];

    // initilaization of 0th row and 0th col with 0
    for(int i = 0 ; i <= W; i++) dp[0][i] = 0; 
    for(int i = 0 ; i <= n; i++) dp[i][0] = 0;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= W; j++) {
            if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


int t[1001][1001];

// Memoriazation Apporach
int knapSackMemo(int W, int wt[], int val[], int n) 
{ 
  
  	if(n == 0 || W == 0) return 0;

  	if(t[n][W] != -1) return t[n][W];

  	if(wt[n-1] <= W) {
  		return t[n][W] = max(val[n-1] + knapSackMemo(W-wt[n-1], wt, val, n-1) , knapSackMemo(W, wt, val, n-1));
  	}
  	else {
  		return t[n][W] = knapSackMemo(W, wt, val, n-1);
  	}

  	return t[n][W];
}



 
int main()
{
	int test;
	cin >> test;

	while(test--) {

		memset(t, -1, sizeof(t));

		int n, w;
		cin >> n >> w;

		int val[n], wt[n];

		for(int i = 0 ; i < n; i++) cin >> val[i];
		for(int i = 0 ; i < n; i++) cin >> wt[i];


		cout << knapSackMemo(w, wt, val, n) << endl;
	}
}

