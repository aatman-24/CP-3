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

Question : Longest Repeating Subsequence.
Topic : DP - LCS Variants.
*/

int LongestCommonRepeatingSubsequence(int X) {

	int n = (int)X.size();
	int dp[n+1][n+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(X[i-1] == X[j-1] && i != j) { // (RESTRICTION)
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][n];
}




int main()
{

	int t;
	string X;
	cin >> t;
	while(t--) {
		cin >> X;
		cout << LongestCommonRepeatingSubsequence(X) << endl;
		
	}

	return 0;

}

