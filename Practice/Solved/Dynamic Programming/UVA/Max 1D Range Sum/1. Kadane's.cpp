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


// Complete Search - O(N^3)
int max1DRangeSum(vi &arr){
	int n = (int)arr.size();
	int ans = arr[0];
	for(int i = 0; i < n-1; i++) {
		for(int j = i+1; j < n; j++) {
			int sum = 0;
			for(int k = i; k <= j; k++) {
				sum += arr[k];
			}
			ans = max(sum, ans);
		}
	}

	return ans;
}

// // Optimal Soultion - O(N^2)
int max1DRangeSum(vi &arr) {
	int n = (int)arr.size();
	int ans = arr[0];
	for(int i = 0; i < n-1; i++) {
		int sum = arr[i];
		for(int j = i + 1; j < n; j++) {
			sum += arr[j];
			ans = max(sum, ans);
		}
	}
	return ans;
}


// // Kadane's Algorithm - O(N).
int max1DRangeSum(vi &arr) {

	int n = (int)arr.size();
	int ans = INT_MIN, sum = 0;   // either use ans = arr[0]. but not 0.

	for(int i = 0; i < n; i++) {
		sum += arr[i];
		ans = max(ans, sum);
		if(sum < 0) sum = 0;
	}

	return ans;

}


int main()
{

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vi arr(n, 0);
		REP(i, n) cin >> arr[i];
		cout << max1DRangeSum(arr) << endl;

	}

}

