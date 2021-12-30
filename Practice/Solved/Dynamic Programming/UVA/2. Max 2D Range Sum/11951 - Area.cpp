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

ll arr[103][103];
ll n,m,limit;

ii max2DRangeSum(int n, int m, ll TM) {

	ll area = 0, UM=0; // UM = used Money 
	ll TC; // Total Cost

	REP(s_i, n) REP(s_j, m) {
		for(int e_i = s_i; e_i < n; e_i++) {
			for(int e_j = s_j; e_j < m; e_j++) {

				TC = arr[e_i][e_j];
				if(s_i > 0) TC -= arr[s_i-1][e_j];
				if(s_j > 0) TC -= arr[e_i][s_j-1];
				if(s_i > 0 && s_j > 0) TC += arr[s_i-1][s_j-1];
				
				ll TA = (e_i - s_i + 1) * (e_j - s_j + 1);
				if(TA >= area) {
					if(TC <= TM) {
						if(TA == area) UM = min(UM,TC);
						else {
							area = TA;
							UM = TC;
						}
					}

				}  
			}
		}
	}

	return ii(area,UM); 

}

int main() {


	int t; cin >> t;
	REP(tc,t) {
		cin >> n >> m >> limit;

		REP(i,n) REP(j,m) {
			cin >> arr[i][j];
			if(i > 0) arr[i][j] += arr[i-1][j];
			if(j > 0) arr[i][j] += arr[i][j-1];
			if(i > 0 && j > 0) arr[i][j] -= arr[i-1][j-1];
		}

		ii ans = max2DRangeSum(n, m, limit);
		cout << "Case #" << tc+1 << ": " << ans.first << ' ' << ans.second << endl;
	}


	return -1;
}