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

Question :  UVa 10635 - Prince and Princess
Topic : DP
// Problems :
*/



int lcsMaxLength(int arr[],int brr[], int n, int m) {

	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(arr[i-1] == brr[j-1]){
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

	int t; cin >> t;
	int n, p, q;
	REP(tc, t){
		cin >> n >> p >> q;
		int arr[p+1], brr[q+1];

		REP(i, p+1) cin >> arr[i];
		REP(i, q+1) cin >> brr[i];

		int maxL = lcsMaxLength(arr,brr,p+1,q+1);
		printf("Case %d: %d\n", ++tc, maxL);
	}
	
	return 0;
}

