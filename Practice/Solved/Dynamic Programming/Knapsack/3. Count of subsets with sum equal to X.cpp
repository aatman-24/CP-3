#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define S second
#define F first

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

int countSubsetTD(int arr[], int S, int n) {

	int dp[n+1][S+1];

	for(int j = 0 ; j <= S; j++) dp[0][j] = 0;
	for(int i = 0; i <= n; i++) dp[i][0] = 1;

	for(int i = 1; i <= n ; i++) {
		for(int j = 0; j <= S; j++) {

			if(arr[i-1] <= j) {
				dp[i][j] = dp[i-1][j - arr[i-1]] + dp[i-1][j];
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][S];
}


int t[1001][1001];
int countSubSetMemo(int arr[], int S, int n) {

	if(S == 0) return 1;
	if(n == 0) return 0;

	if(t[n][S] != -1) return t[n][S];

	if(arr[n-1] <= S) {
		return t[n][S] = countSubSetMemo(arr, S-arr[n-1], n-1) + countSubSetMemo(arr, S, n-1);
	}
	else {
		return t[n][S] = countSubSetMemo(arr, S, n-1);
	}

}


int main()
{
	int test; cin >> test;
	int N, S;
	while(test--) {
		cin >> N >> S;
		
		memset(t, -1, sizeof(t));
		int arr[N];
		for(int i = 0 ; i < N; i++) cin >> arr[i];

		// cout << countSubsetTD(arr, S, N) << endl;

		cout << countSubSetMemo(arr, S, N) << endl;


	}
}

