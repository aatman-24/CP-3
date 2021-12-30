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

Question : Longest Common Subsequence
Topic : DP - LCS (root)
*/

// return LCS length.

int t[101][101];

int lcsBU(int n, int m, string s1, string s2){
	  
	// Base condition for empty string return 0.
	if(n == 0 || m == 0) return 0;

	if(t[n][m] != -1) return t[n][m];

	if(s1[n-1] == s2[m-1]) {
		return t[n][m] = 1 + lcsBU(n-1, m-1, s1, s2);
	}
	else {
		return t[n][m] = max(lcsBU(n-1, m, s1, s2), lcsBU(n, m-1, s1, s2));
	}


}



int lcsTD(int n, int m, string s1, string s2) {

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	// Initialization both 0th row and 0th col with 0 with already done in memset

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]) {
				// If at ith index both character is equal move to the next character.
				dp[i][j] = 1 + dp[i-1][j-1]; 
			}
			else {
				// If not equal max((s1->index-1,s2->jndex),(s1->index, s2->jndex-1))
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	REP(i,n) {
		REP(j,m) {
			cout << dp[i][j] << ' ';
		}
	}


	return dp[n][m];


	// print the lcs sequence.
	// string res_lcs = "";
	// int i = n, j = m;
	// while(i > 0 && j > 0) {
	// 	if(s1[i-1] == s2[j-1]) {
	// 		res_lcs.push_back(s1[i-1]) // add into the result string.
	// 	}
	// 	else {
	// 		if(dp[i-1][j] >= dp[i][j-1]) i--;
	// 		else j--;
	// 	}
	// }

	// reverse(res_lcs.begin(), res_lcs.end());
	// cout << res_lcs << endl;

}


// print the LCS.  

int main()
{

	int test, n, m;
	string S1, S2;
	cin >> test;
	while(test--) {
		cin >> n >> m;
		cin >> S1 >> S2;
		// memset(t, -1, sizeof(t));
		cout << lcsTD(n, m, S1, S2) << endl;
	}
	return 0;

}

