#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REPN(i,n) for(int i = 0; i <= n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
// #define S second
// #define F first

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

Question : 
Topic : 

*/

int subsetSum(int arr[], int n, int S) {

	int dp[n+1][S+1];
	memset(dp, 0, sizeof(dp));

	for(int j = 0; j <= S; j++) dp[0][j] = 0;
	for(int i = 0; i <= n; i++) dp[i][0] = 1;

	for(int i = 1 ; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][S];

}

int subsetDif(int arr[], int n , int D) {

	int T = 0;
	for(int i = 0 ; i < n; i++) T += arr[i];

	if(D > T || (T+D % 2 == 1)) return 0;

	return subsetSum(arr, n, ((T+D)/2));

}


int main()
{
	int N, D;
	int test; cin >> test;
	while(test--) {
		cin >> N >> D;
		int arr[N];
		REP(i, N) cin >> arr[i];

		cout << subsetDif(arr, N , D) << endl;
	}

}

