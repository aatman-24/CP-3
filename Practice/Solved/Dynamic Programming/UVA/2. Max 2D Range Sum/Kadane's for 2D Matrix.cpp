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

Question : 	10684 - The jackpot
Topic : DP(Kadene's Variants)

*/


int arr[100][100];

Complete Search - O(N^6)
s -> start e->end r->range 
int max2DRangeSum(int n) {
	int ans = INT_MIN;
	int subRect;
	REP(s_i,n) REP(s_j,n)
		REP(e_i,n) REP(e_j,n) {
			subRect = 0;
			for(int r_s = s_i; r_s <= e_i; r_s++) {
				for(int r_e = s_j; r_e <= e_j; r_e++) {
					subRect += arr[r_s][r_e];
				}
			}
			ans = max(ans, subRect);
		}
	return ans;

}

// Kadane's Algorithm - O(N^4)
int max2DRangeSum(int n) {


	int subRect,ans = INT_MIN;
	REP(s_i,n) REP(s_j,n) {
		for(int e_i = s_i; e_i < n; e_i++) {
			for(int e_j = s_j; e_j < n; e_j++) {
				subRect = arr[e_i][e_j];

				// remove already added sum.
				if(s_i > 0) subRect -= arr[s_i-1][e_j];
				if(s_j > 0) subRect -= arr[e_i][s_j-1];
				if(s_i > 0 && s_j > 0) subRect += arr[s_i-1][s_j-1];	// two time subtract so add one time.
				ans = max(subRect, ans);
			}
		}
	}

	return ans;
}

int main()
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		REP(i,n) REP(j,n) {
			cin >> arr[i][j];

			// cumulative sum
			if(i > 0) arr[i][j] += arr[i-1][j]; 
			if(j > 0) arr[i][j] += arr[i][j-1];
			if(i > 0 & j > 0) arr[i][j] -= arr[i-1][j-1]; // two times added so add one time.
		}
		cout << max2DRangeSum(n) << endl;
	}
}

