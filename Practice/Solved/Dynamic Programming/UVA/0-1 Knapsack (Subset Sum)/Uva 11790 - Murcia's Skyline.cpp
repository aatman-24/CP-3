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
Topic : 0-1 Knapsack (Subset Sum)

*/

/*
NOTE : if (a >= 0) d = a % b
  	  else d = (a % b) + b; if(a < 0) you also have to add b again.
*/


ll arr[201];
ll N,D,TS;

ll t[201][31][31];

 //[given_N][taken_num][sum] this problem is simple SubsetSum. But here problem is that
// we can not store all possible sum which we take 3rd index.
// for that as per the question we store current_sum % 20 into pos.

ll SubsetSum(int N, int M, int S) {

	ll tmp;
	if((TS - S) <= 0) tmp = ((TS-S)%D + D);
	else tmp = (TS-S) % D;


	ll &ret=t[N][M][tmp];
	if(ret != -1) return ret;


	if((TS - S) % D == 0  && M==0) {
		return ret = (ll)1;
	}

	if(N == 0 || M == 0) return ret = (ll)0;

	return ret = SubsetSum(N-1, M-1, S-arr[N-1]) + SubsetSum(N-1, M, S);
}



int main()
{
	ll Q;
	ll tc = 0;
	while(cin >> N >> Q) {
		if (N == 0 && Q == 0) break;
		cout << "SET " << ++tc << ':' << endl;
		REP(i, N) cin >> arr[i];
		TS = accumulate(arr, arr+N, (ll)0);

		vii query(Q, ii(0,0));
		REP(i, Q) cin >> query[i].first >> query[i].second;
		REP(i, Q) {

			memset(t, -1 , sizeof(t));
			D = query[i].first;
			cout << "QUERY "<< i+1<< ": " << SubsetSum(N, query[i].second, TS) << endl;
		}

	}

}

