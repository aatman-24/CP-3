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

Question : PRINT SHORTEST COMMON SUPERSEQUNCE (SCS)
Topic : DP - LCS Variants.
*/

// Printing Shortest Common Supersequence
string printSCS(string X, string Y) {

	int n = (int)X.size();
	int m = (int)Y.size();

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


	int i = (int)X.size();
	int j = (int)Y.size();
	string SCS = "";
	while(i > 0 && j > 0) {
		if(X[i-1] == Y[j-1]) { // DIAGONAL ELEMENT ADDED ONE TIME.
			SCS += X[i-1];
			i--; j--;
		}
		else {
			if(dp[i][j-1] >= dp[i-1][j]) { // IF VALUE IN DP TABLE FROM THE UPPER SIDE THEN FIRST ADD THE ELEMENT AND THEN MOVE.
				SCS += Y[j-1];
				j--;
			}
			else {
				SCS += X[i-1]; // IF VALUE IN DP TABLE FROM THE LEFT SIDE THEN FIRST ADD THE ELEMENT AND THEN MOVE.
				i--;
			}
		}
	}


	// IN LCS IF I == 0 OR J == 0 MEANS THAT NO COMMONE SEQUENCE FOUND AFTER THAT.
	// LCS(PHI, AB) = PHI. (NO COMMON SEQ).
	// BUT HERE SCS WE ARE FINDING SUPERSEQUNCE MEANS THAT,
	// SUPERSEQUNCE(PHI, AB) = AB. (THE SECOND STRING IS SUPERSEQUNCE WHICH CONTAIN BOTH STRING.)
	// SO AFTER IF I > 0 OR J > 0 (ONLY ONE IS EXECUTED NOT BOTH) WE ADD REMAINING STRING INTO RESULT.
	while(i > 0) {
		SCS += X[i-1];
		i--;
	}

	while(j > 0) {
		SCS += Y[j-1];
		j--;
	}

	reverse(SCS.begin(), SCS.end());

	return SCS;
}

int main()
{

	int t;
	string X,Y;
	cin >> t;
	while(t--) {
		cin >> X >> Y;
		cout << printSCS(X,Y) << endl;
		
	}

	return 0;

}

