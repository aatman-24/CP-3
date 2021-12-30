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

Question :  11517	Exact Change
Topic : UNBOUNDED KNAPSACK variants.

*/

int ans_money;
int ans_coin; 
int TM;


int tCoins[110][10010];
int tMoney[110][20010];
int coins[110];

ii coinChange(int N, int CM) {

	if(N == 0 && CM < TM){
		return ii(INT_MAX, INT_MAX); // if we have no coin and current_money is less than it is not possible.
	}

	if(CM >= TM) {
		return ii(CM, 0); // Currnet Money greater or equal than we return it.
	}

	int &m = tMoney[N][CM];
	int &c = tCoins[N][CM];
	if(m != -1) {
		return ii(m,c);
	}

	ii pair1 = coinChange(N-1, CM + coins[N-1]);
	ii pair2 = coinChange(N -1, CM);
	pair1.second += 1; // Added coins so upcount it.

	ii res = min(pair1, pair2);

	m = res.first;
	c = res.second;

	return res;
}

int main()
{
	int tC; cin >> tC;
	int N;
	while(tC--) {
		cin >> TM >> N;

		memset(tMoney, -1, sizeof(tMoney));
		memset(tCoins, -1, sizeof(tCoins));

		ans_money = ans_coin = INT_MAX-1;
		REP(i, N) cin >> coins[i];
		ii ans =  coinChange(N, 0);
		cout << ans.first << ' ' << ans.second << endl;
		// cout << ans_money << ' ' << ans_coin << endl;
	}
}