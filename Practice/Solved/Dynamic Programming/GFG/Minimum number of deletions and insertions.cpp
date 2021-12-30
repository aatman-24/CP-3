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

Question : MIN-# OF INSERTION AND DELETION TO CONVERT A INTO B.
Topic : DP - LCS Variants.
*/

class Solution{
		
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = (int)str1.length();
	    int n = (int)str2.length();
	    
	    
	    int dp[m+1][n+1];
	    memset(dp, 0, sizeof(dp));
	    
	    
	    for(int i = 1; i <= m; i++) {
	        for(int j = 1; j <= n; j++) {
	            
	            if(str1[i-1] == str2[j-1]) {
	                dp[i][j] = 1 + dp[i-1][j-1];
	            }
	            else {
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	            }
	        }
	    }
	    
	    int lcs_length = dp[m][n];
	    
	    int delete_opreation = m - lcs_length;
	    int insert_opreation = n - lcs_length;
	    
	    return delete_opreation + insert_opreation;
	    
	} 
};

int main()
{

	int t;
	string X, Y;
	cin >> t;
	while(t--) {
		cin >> X >> Y;

		Solution ob;
		cout << ob.minOperations(X, Y) << endl;
		// cout << minNumberOfOpration(X, Y, X.size(), Y.size());
	}

	return 0;

}

