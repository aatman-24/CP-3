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

Question : Sequence Pattern Matching.
Topic : DP - LCS Variants.
*/


// HERE WE FIND THAT GIVEN STRING X IS SUBSEQUNCE INTO THE STRING Y. CHECK->    X -> LCS(X,Y)
// OR SOMETIME WE GIVEN THAT GIVEN X AND Y, IS THERE ANY SUBSEQUNCE OF ANOTHER. CHECK -> MIN(X,Y) = LCS(X,Y)


// Return String x is subsequnce into the Y.
bool XIsSubsequnceIntoY(string X, string Y) {

	int n = (int)X.size();
	int m = (int)Y.size();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(X[i-1] == Y[j-1]) { // we cannot take one element for the two time.
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return (dp[n][m] == n);
}




int main()
{

	int t;
	string X, Y;
	cin >> t;
	while(t--) {
		cin >> X >> Y;
		cout << XIsSubsequnceIntoY(X,Y) << endl;
		
	}

	return 0;

}

