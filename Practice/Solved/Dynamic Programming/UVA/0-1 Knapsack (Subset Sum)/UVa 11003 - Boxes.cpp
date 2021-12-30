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

Question : UVa 11003 - Boxes
Topic : 0-1 Knapsack 

*/

ll wt[1010], max_load[1010];

ll t[1010][6001];  

// Why? 6001 -> MAX_LOAD CAN BE 3000. NOW SUPPOSE TWO BOX WITH WEIGHT 3000 3000 = 6000 CAN BE MAXIMUM
// BCZ IF MAX_LOAD > 3000 THE WEIGHT IS NOT ADDED INTO THE CUR_WEIGHT SO LAST VALUE CAN BE
// t[x][6000] = 0 which also note added.


// 2800 3000 2900 -> 2900(A) -> 2900+3000(R) (but for the storage we must have index t[x][2900+3000]) -> 2800 [(2800 + 2900)] can be sum.

// so max index is 3000 + 3000 = 6000 so we take here 6001.

int solve(int N, int cw) {

	if(N == 0) return t[N][cw] = 0;

	if(t[N][cw] != -1) return t[N][cw];

	if(cw <= max_load[N-1]) {
		return  t[N][cw] = max(1 + solve(N-1, wt[N-1] + cw), solve(N-1, cw));
	}
	else {
		return  t[N][cw] = solve(N-1, cw);
	}

}


int main()
{
	// int t; cin >> t;
	int N;
	while(cin >> N) {
		if(N == 0) break;
		REP(i, N) cin >> wt[i] >> max_load[i];
		memset(t, -1, sizeof(t));
		cout << solve(N, 0) << endl;
	}


}