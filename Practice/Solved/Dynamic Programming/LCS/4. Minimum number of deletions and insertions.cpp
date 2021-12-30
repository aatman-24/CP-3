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

Question : MIN-# OF INSERTION AND DELETION TO CONVERT A INTO B.
Topic : DP - LCS Variants.
*/

int LCSTD(string X, string Y, int n, int m) {

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {

			if(X[i-1] == Y[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int minNumberOfOpration(string X, string Y, int n, int m) {
	int lcsLen = LCSTD(X, Y, n, m);
	int delOpreation = n - lcsLen;
	int insertOpreation = m - lcsLen;
	return delOpreation + insertOpreation;
}

int main()
{

	int t;
	string X, Y;
	cin >> t;
	while(t--) {
		cin >> X >> Y;
		cout << minNumberOfOpration(X, Y, X.size(), Y.size());
	}

	return 0;

}

