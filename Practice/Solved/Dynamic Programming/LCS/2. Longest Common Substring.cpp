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

Question : longestCommonSubstring
Topic : LCSubString.
*/


int t[1001][1001];
int cnt = 0;
int max_length = 0;

int longestCommonSubstringMEMO(string s1, string s2, int n, int m) {

	if(n == 0 || m == 0) return 0;
	if(t[n][m] != -1) return t[n][m];
	if(s1[n-1] == s2[m-1]) {
		cnt = 1 + longestCommonSubstring(s1, s2, n-1, m-1); // both char match.
		if(max_length < cnt) max_length = cnt; // stole the max_length.
	}
	else {
		// here we call the next subsequence call for creating the tree.
		longestCommonSubstring(s1, s2, n-1, m);
		longestCommonSubstring(s1,s2, n, m-1);
		cnt = 0; // we return 0 bcz s1[i] != s2[j].
	}
	return t[n][m] = cnt;
} 

int longestCommonSubstringTD(string s1, string s2, int n, int m) {

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	// max_length of the substring 
	int max_length = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]) {
				dp[i][j] = 1 + dp[i-1][j-1];
				// update if we found maxSubString.
				if(dp[i][j] > max_length)  max_length = dp[i][j];
			}
			else {
				// If any Time if ith and jth char not match that means he can not be substring.
				// so here we store length 0.
				dp[i][j] = 0;
			}
		}
	}

	// here we don't return dp[n][m]. (reason is that In table we store the [i,j] is consecutive substring.
	// that means here only if (i-1,j-1) is same and (i,j) is same then and only "" 1 + lcsubstring(i-1,j-1) "")
	// here we track the max_length in the loop it is also possible that at a last you traverse and find
	// the max length.
	return max_length;
}


int main()
{

	int test, n, m;
	string S1, S2;
	cin >> test;
	while(test--) {
;
		cin >> S1 >> S2;
		n = (int)S1.size();
		m = (int)S2.size();
		


		cnt = 0;
		max_length = 0;
		memset(t, -1, sizeof(t))
		longestCommonSubstringMEMO(S1, S2, n, m);
		cout << max_length << endl;



		cout << longestCommonSubstringTD(S1, S2, n, m) << endl;
	}
	return 0;

}

