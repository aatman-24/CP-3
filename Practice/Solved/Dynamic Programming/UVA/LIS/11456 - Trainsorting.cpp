#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define F first 
#define S second

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

Question : 	11456 - Trainsorting
Topic : DP(LIS, LDS)

*/

// // Try all numbers and find LIS and LDS which start from this number
// and answer will be max(LDS(i) + LIS(i) - 1) -1 bcz number is counted on both LIS and LDS.

int LIS(vi arr, int sIndex) {
	int n = (int)arr.size();
	vi lis;
	lis.push_back(arr[sIndex]);
	for(int i = sIndex+1; i < n; i++) {
		if(lis.back() < arr[i]) {
			lis.push_back(arr[i]);
		}
		else {
			int pos = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
			if(pos != 0) lis[pos] = arr[i];
		}
	}
	return lis.size();
}


int LDS(vi arr, int sIndex) {
	int n = (int)arr.size();
	vi lds;
	lds.push_back(arr[sIndex]);
	for(int i = sIndex + 1; i < n ; i++) {
		if(lds.back() <= arr[i]) {
			int index = lds.size() - 1;
			while(index >= 0) {
				if(lds[index] < arr[i]) index--;
				else break;
			}
			if(index > -1) lds[index+1] = arr[i];
		}
		else {
			lds.push_back(arr[i]);
		}
	}
	return lds.size();
}




int main()
{
	int t; cin >> t;

	while(t--) {
		int n; cin >> n;
		vi arr(n,0);
		REP(i,n) cin >> arr[i];
		int ans = INT_MIN;
		REP(sIndex,n) {
			ans = max(LDS(arr,sIndex) + LIS(arr,sIndex) - 1, ans);
		}
		cout << max(ans,0) << endl;
	}

}

