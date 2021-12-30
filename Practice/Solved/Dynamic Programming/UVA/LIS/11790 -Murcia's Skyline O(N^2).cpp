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

Question : 		11790 - Murcia's Skyline
Topic : DP(LIS, LDS)

*/

ii soultion(vi height, vi width) {
	int n = height.size();
	vi lis(width);
	vi lds(width);

	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(height[i] < height[j] && lis[i] + width[j] > lis[j]) lis[j] = lis[i] + width[j];
			if(height[i] > height[j] && lds[i] + width[j] > lds[j]) lds[j] = lds[i] + width[j];
		}
	}

	int lis_max = *max_element(lis.begin(), lis.end());
	int lds_max = *max_element(lds.begin(), lds.end());
	return ii(lis_max, lds_max);

}



int main()
{
	int t; cin >> t;

	REP(tc, t) {
		int n; cin >> n;
		vi height(n,0), width(n,0);
		REP(i,n) cin >> height[i];
		REP(i,n) cin >> width[i];
		ii costs = soultion(height, width);
		int lisCost = costs.first;
		int ldsCost = costs.second;
		if(lisCost >= ldsCost) {
			printf("Case %d. Increasing (%d). Decreasing (%d).\n", tc+1, lisCost, ldsCost);
		}
		else {
			printf("Case %d. Decreasing (%d). Increasing (%d).\n", tc+1, ldsCost, lisCost);
		}
	}

}

