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

Question : 507 - Jill Rides Again
Topic : DP(kadane - variants).
*/

// 1	2	3	4	5	6	7	8	9	 10	 11	 12	 13	 14 (stations)
//  -94 -67  73  3   80  2  -91 -90  -90  81  75   1  1 (value)


// using kadane algorithm we can find in O(N).
// here if we need to get range longest if sum is equal. (it is tackle with ans >= sum)
// if range is equal also then range which start first. (for 
 // this we use two pointer r_s and r_e which we patch when the ans is updated
 // to track the previous start and end.
 // if(ans == sum) then if(cur range is bigger than and only updated otherwise not).
 // 	)




ii max1DRangeSum(int arr[], int n) {

	int start, end, r_s, r_e;
	int ans = INT_MIN, sum = 0;
	start = 1; end = 1;

	for(int i = 0; i < n; i++) {

		sum += arr[i];

		if(sum < 0) {
			start = i+2;
			sum = 0;
		}

		if((sum > ans) || (sum == ans && ((r_e - r_s) < (i+2 - start)))) {   // (here i+2 represe the current end point.)
			ans = max(ans, sum);
			end = i+2;
			r_e = end; r_s = start;		
		}

		
	}

	return ii(r_s,r_e);

}


int main() {

	int t; cin >> t;
	int numS;
	for(int r = 0; r < t; r++) {
		cin >> numS;
		int arr[numS];
		for(int i = 0; i < numS-1; i++) cin >> arr[i];
		ii ans =  max1DRangeSum(arr, numS-1);
		if(ans.first == ans.second) {
			printf("Route %d has no nice parts\n", r+1);
			// cout << "Route " << r+1 << " has no nice parts" << endl;
		}
		else {
			printf("The nicest part of route %d is between stops %d ans %d\n", r+1, ans.first, ans.second);
			// cout << "The nicest part of route " << r + 1 << " is between stops "<< ans.first << " and " << ans.second << endl;
		}

	}

}