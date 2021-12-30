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

// Return True if one of the arr subset sum is equal to S else false.
bool subsetSumTD(int arr[], int S, int n) {
    
    bool dp[n+1][S+1];
    
    // Initiallization [0,0] = T, 0th-col -> T, 0th-raw -> F
    for(int j = 0 ; j <= S; j++) dp[0][j] = false;
    for(int i = 0 ; i <= n; i++) dp[i][0] = true;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= S; j++) {
            if(arr[i-1] <= S) {
                dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    return dp[n][S];
}

int t[1001][1001];

bool subsetSumMemo(int arr[], int S, int n) {

    if(S == 0) return 1;
    if(n == 0) return 0;

    if(t[n][S] != -1) return t[n][S];

    if(arr[n-1] <= S) {
        return t[n][S] = subsetSumMemo(arr, S-arr[n-1], n-1) || subsetSumMemo(arr, S, n-1);
    }
    else {
        return t[n][S] = subsetSumMemo(arr,S,n-1);
    }
}




int equalPartition(int N, int arr[])
    {
        int sum_tmp = 0;
        for(int i = 0; i < N; i++) sum_tmp += arr[i];

        if(sum_tmp % 2) return 0; // odd sum is not divided into two parts.
        else{
            return (int)subsetSumTD(arr, sum_tmp/2, N);
        }
    }


 
int main()
{
	int t; cin >> t;
	while(t--) {
		int N; cin >> N;
		int arr[N];
		for(int i = 0 ; i < N; i++)  cin >> arr[i];

		if(equalPartition(N, arr)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

