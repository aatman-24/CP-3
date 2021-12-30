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
class Solution {
public:

	int numSubset(vector<int>& arr, int S) {
	
		int n = (int)arr.size();

		vvi dp(n+1, vi(S+1, 0)); // used 2d Vector.

		// initialize the table
		for(int j = 0; j <= S; j++) dp[0][j] = 0;
		for(int i = 0; i <= n ; i++) dp[i][0] = 1;

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


    int findTargetSumWays(vector<int>& nums, int S) {
        int total = 0;
        REP(i,(int)nums.size()) total += nums[i];


      	if ((total + (long) S) % 2 == 1 || total < S)
      		return 0;


        return numSubset(nums, (S + total) / 2);
        
    }
};


int main()
{
	int N, S;
	int test; cin >> test;
	while(test--) {
		cin >> N >> S;
		vi arr(N,0);
		REP(i, N) cin >> arr[i];

		Solution ob;

		cout << ob.findTargetSumWays(arr, S) << endl;

	}

}

