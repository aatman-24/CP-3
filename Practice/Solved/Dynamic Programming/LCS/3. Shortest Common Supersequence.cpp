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

Question : Shortest Common Supersequence
Topic : DP - LCS Variants.
*/


int lcsTC(char *X, char *Y, int m, int n) {

	int dp[m+1][n+1];

	memset(dp, 0, sizeof(dp));


	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(X[i-1] == Y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}	
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[m][n];

}

int shortestCommonSupersequence(char* X, char* Y, int m, int n) {
	// worst supersequence is X + Y.
	// but for shortest sequence we are going to remove element which is already occurs.
	// which is lcs of both string. 
   return m + n - lcsTC(X, Y, m, n);
}


int main()
{


	int t;
	char X[10001], Y[10001];

	cin >> t;
	while(t--) {
		cin >> X >> Y;

		cout << shortestCommonSupersequence(X, Y, strlen(X), strlen(Y));
	}

	return 0;

}

