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

Question : Matrix Chain Mutliplication.
Topic : DP(One Of the Most FAv).
*/



int t[101][101];
int min_op;


int MCM_Memo(int arr[], int i, int j) {
	if(i >= j) return 0;
	if(t[i][j] != -1) return t[i][j];

	// Here We need min_op from all the possible partition and we choose it.
	// If we declare min_op as global it will give wrong answer bcz the leaves of tree is the min_op
	// which is wrong we need from all the partition and whatever min value given we must choose it and
	// sum with root cost.
	int min_op = INT_MAX;
	for(int k = i; k < j; k++) {
		int tmp_cost = MCM_Memo(arr,i,k) + MCM_Memo(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
		min_op = min(tmp_cost, min_op);
	}

	return t[i][j] = min_op;

}





int main()
{

	int test;
	cin >> test;
	while(test--) {
		memset(t, -1, sizeof(t));
		int N; cin >> N;
		int arr[N];
		for(int i = 0; i < N; i++) cin >> arr[i];
		cout << MCM_Memo(arr, 1, N-1) << endl;
		
	}

	return 0;

}

