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


int max1DRangeSum(int arr[], int n) {

	int ans = INT_MIN,sum = 0;
	REP(i, n) {
		sum += arr[i];
		if(sum < 0) sum = 0;
		ans = max(sum, ans);
	}
	return ans;

}


int main()
{

	while(true) {
		int n; cin >> n;
		if(!n) break;

		int arr[n];
		REP(i,n) cin >> arr[i];

		int ans = max1DRangeSum(arr, n);
		if(ans > 0) {
			printf("The maximum winning streak is %d.\n",ans);
		} 
		else {
			printf("Losing streak.\n");
		}
	}

}

