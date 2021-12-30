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

Question : MIN # OF DELETION TO MAKE A PALINDROME.
Topic : DP - LCS Variants.
*/


int LCSTD(string X, string Y) {

	int n = (int)X.size();
	int m = (int)Y.size();


	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));


	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {

			if(X[i-1] == Y[i-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[n][m];
}

int LongestPalindromeSubsequence(string X) {
	string Y = X;
	reverse(Y.begin(), Y.end());
	return LCSTD(X,Y);
}

int minimumNumberOfDeletions(string X) {
	return (int)X.size() - LongestPalindromeSubsequence(X);
}


int main()
{

	int t;
	string X;
	cin >> t;
	while(t--) {
		cin >> X;
		cout << minimumNumberOfDeletions(X) << endl;
		
	}

	return 0;

}

