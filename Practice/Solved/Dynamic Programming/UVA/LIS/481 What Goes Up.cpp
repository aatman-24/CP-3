#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Apporach <=============================================

Question : 11951 - Area
Topic : DP(kadane - variants), max2DRangeSum.
*/


// void LIS(vi arr) {

// 	int n = (int)arr.size();
// 	vi lis(n, 1);

// 	for(int i = 1; i < n; i++) {
// 		int j = i - 1;
// 		while(j >= 0 && arr[j] > arr[i]) j--;
// 		if(j >= 0) lis[i] = (arr[i] == arr[j]) ? lis[j] : lis[j] + 1;
// 	}

// 	int te =  *max_element(lis.begin(), lis.end());

// 	cout << te << endl;
// 	cout << '-' << endl;
// 	// REP(i, n) cout << lis[i] << ' ';
// 	// cout << endl;

// 	vi elements(te, 0);
// 	int cnt = te;
// 	for(int i = n-1; i >= 0; i--) {
// 		if(lis[i] == (cnt)) {
// 			elements[--cnt] = arr[i];
// 		}
// 	}

// 	REP(i,te) cout << elements[i] << endl;

// }




// print the all number starting from the first to the last.
void print(vi &arr, vi &path, int index) {
	if(index == -1) return;
	print(arr, path, path[index]);
	cout << arr[index] << endl;
}

// print the total lenght of the LIS and also print all LIS numbers.
void LIS(vi arr) {
	int n = (int)arr.size();

	// lisIndex store the lis index, path store the previous lis index.
	vi lis(n,0), lisIndex(n,0), path(n,0);

	int lisCount = 0;
	for(int i = 0; i < n; i++) {
		// lower_bound return the pos where the element is going to fit.
		int pos = lower_bound(lis.begin(), lis.begin() + lisCount, arr[i]) - lis.begin();
		
		
		lis[pos] = arr[i]; // store the number to the pos.
		lisIndex[pos] = i; // store the index
		path[i] = (pos>0) ? lisIndex[pos-1] : -1; // for the first number store -1 and for other lis store previous lis index.
		if(lisCount == pos) lisCount++; // true when new LIS is found.
	}

	cout << lisCount << endl; // LIS length
	// cout << '-' << endl;
	int lastNumIndex = lisIndex[lisCount-1]; // last LIS Index.
	print(arr, path, lastNumIndex); 
}

int main() {
	vi arr;
	int i;
	while(cin >> i) {
		arr.push_back(i);
	}
	LIS(arr);
	return -1;
}


