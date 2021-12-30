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

Question : 
Topic : 

*/


/*

Apporach : Here we given arr = [1 5 6 11] and find out abs(s1 - s2) which is minimum.

s1 + s2 = T
s1 - s2 = (T - s2) - s2 = min(T - 2 * s2)
we go upto the T/2 element bcz we take constriant s1 > s2.

check the video.

- get range first (0, T)
- minimize variable from s1,s2 -> define problem on single variable here s2 -> (T - 2*s2)
- use dp (last raw is matter) (It say that for given n is it possible to make i subset sum).

*/


// i think we should use dp[][] this as per the requirement in dp. bcz 
// sometime use face dp[100][10000] , dp[1][1000000], dp[100000][1] if you make static array
// like dp[1000][1000] it is not work for above which is true.

class Solution{

	public:

	int subsetSumTD(int arr[], int n, int S, int T) {

		bool dp[n+1][S+1];
    	memset(dp, 0, sizeof(dp));
    
    	// initilization of [0,0] -> true 0th row -> false 0th col -> True
    	for(int j = 0; j <= S; j++) dp[0][j] = false;
    	for(int i = 0 ;i <= n; i++) dp[i][0] = true;
    
    
        // generate dp table which is subsetSum(int arr[], int sum) equals.
    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= S; j++) {
    
    			if(arr[i-1] <= j) {
    				dp[i][j] = (dp[i-1][j - arr[i-1]] || dp[i-1][j]);
    			}
    			else {
    				dp[i][j] = dp[i-1][j];
    			}
    
    		}
    	}

        // Now From the last raw choose most promising value.
    	int min_differnce = INT_MAX;
    	for(int i = 0 ; i <= S; i++) {
    		if(dp[n][i]) {
    			if((T - 2*i) < min_differnce) min_differnce = (T -2*i);
    		}
    	}
    
    	return min_differnce;
   }
	
	
	int minDiffernce(int arr[], int n) 
	{ 
	   int sum_tmp = 0;
    	for(int i = 0 ; i < n; i++) sum_tmp += arr[i]; 
    	return subsetSumTD(arr, n, sum_tmp/2, sum_tmp);
   
	} 
};
 
int main()
{

	int t;
	cin >> t;
	while(t--) {
		int n; cin >> n;
		int a[n];
		
		for(int i = 0 ; i < n ;i++) cin >> a[i];

		Solution ob;
		cout << ob.minDiffernce(a,n) << endl; 
	}
	return 0;

}

