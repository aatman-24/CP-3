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
==============================> Description <=============================================

Question : 	10684 - The jackpot
Topic : DP(Kadene's Variants)

*/


// return length of LIS. -> O(N^2)
int LongestIncreasingSeq(int arr[], int n) {

	vi LIS(n,1);
	int j;

	for(int i = 1; i < n; i++) {
		j = i-1;
		while(j >= 0 && arr[j] > arr[i]) j--;
		if(j >= 0) LIS[i] = (arr[i] == arr[j]) ? (LIS[j]) : (LIS[j] + 1);
	}

	// Print LIS.
	// int cnt = 0;
	// REP(i,n) {
	// 	if(LIS[i] > cnt) {
	// 		cout << arr[i] << ' ';
	// 		cnt++;
	// 	}
	// }
	// cout << endl;

	return *max_element(LIS.begin(), LIS.end());
}



// O(N*logK) K = lengthOFLIS.   lower_bound -> point to equal element or just greater than that element.
int LongestIncreasingSeq(int arr[], int n) {
	vi LIS;
	LIS.push_back(arr[0]);
	for(int i = 1; i < n; i++) {
		if(LIS.back() < arr[i]) LIS.push_back(arr[i]);
		else {
			int index = lower_bound(LIS.begin(), LIS.end(), arr[i]) - LIS.begin();
			LIS[index] = arr[i];
		}
	}
	return LIS.size();
}



int main()
{
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int arr[n];
		REP(i,n) cin >> arr[i];
		cout << LongestIncreasingSeq(arr, n) << endl;
	}
}

