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

Question : longestCommonSubstring
Topic : LCSubString.
*/


class Solution{
    public:

    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        memset(dp, 0, sizeof(dp));

        int max_len = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(S1[i-1] == S2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                    if(dp[i][j] > max_len)  max_len = dp[i][j];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return max_len;
    }
    
 
};

int main()
{

    int test, n, m;
    string S1, S2;
    cin >> test;
    while(test--) {
;
        cin >> S1 >> S2;
        n = (int)S1.size();
        m = (int)S2.size();
        
        cout << longestCommonSubstr(S1, S2, n, m) << endl;
    }
    return 0;

}

