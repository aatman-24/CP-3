#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Description <=============================================

Question : String Alignment (Edit Distance) Needleman-Wunsch’s
Topic : 
// Problems :
*/

int lcsMaxLength(string s1,string s2) {

	int n = s1.size(), m = s2.size();

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

	return dp[n][m];

}




int main() {

	string s1, s2;
	
	int tc = 0;
	while(getline(cin,s1)) {
		if(s1 == "#") break;
		getline(cin,s2);
		// for(int i = 0; i < s1.size(); i++) {
		// 	if(s1[i] == ' ') {
		// 		s1[i] = '_';
		// 	}
		// }

		// for(int i = 0; i < s2.size(); i++) {
		// 	if(s2[i] == ' ') {
		// 		s2[i] = '_';
		// 	}
		// }


		int maxL = lcsMaxLength(s1,s2);

		printf("Case #%d: you can visit at most %d cities.\n", ++tc, maxL);
	}


	return 0;
}

