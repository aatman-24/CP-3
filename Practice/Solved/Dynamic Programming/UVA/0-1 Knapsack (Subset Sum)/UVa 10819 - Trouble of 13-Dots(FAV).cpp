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

Question :UVa 10819 - Trouble of 13-Dots
Topic : 0-1 Knapsack (Subset Sum)

*/

int wt[101], val[101];
int t[101][10000];  
int TM;


int solve(int N, int UM) {

	if(N == 0)
    {
        if (UM <= TM || (UM > 2000 && UM <= TM + 200))
            return 0;
        else
            return -20000;
    }

	int &best = t[N][UM];
	if(best == -1) {

		int increased_M = wt[N-1] + UM;
		int other = -1;

		if(increased_M <= TM + 200) {
			other = val[N-1] + solve(N-1, increased_M);
		}
		best = solve(N-1, UM);
	
		if(other >= 0 || best >= 0) {
			best = max(best, other);
		}
	}
	return best;
}



int main()
{

	int N;
	while(cin >> TM) {
		cin >> N;
		REP(i, N) cin >> wt[i] >> val[i];
		memset(t, -1, sizeof(t));
		cout << solve(N, 0) << endl;
	}
}