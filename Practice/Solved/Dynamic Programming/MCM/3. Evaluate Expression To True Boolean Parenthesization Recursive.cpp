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

Question : Boolean Parenthesization (MCM-Varints).
Topic : DP.
*/

int countWays(string S, int i, int j, bool isTrue) {

	if(i > j) return 0;

	if(i == j) {
		if(isTrue) {
			return S[i] == 'T' ? 1 : 0;
		}
		else {
			return S[i] == 'F' ? 1 : 0;
		}
	}

	int totalWay = 0;
	for(int k = i + 1; k < j; k+=2) {

		int lT = countWays(S, i, k-1, true);
		int lF = countWays(S, i, k-1, false);
		int rT = countWays(S, k+1, j, true);
		int rF = countWays(S, k+1, j, false);

		if(S[k] == '|') {
			if(isTrue) {
				totalWay = totalWay + (lF * rT) + (lT * rF) + (lT * rT);
			}
			else {
				totalWay = totalWay + (lF * rF);
			}
		}
		else if(S[k] == '&') {
			if(isTrue) {
				totalWay = totalWay + (lT * rT);
			}
			else {
				totalWay = totalWay + (lF * rT) + (lF * rF) + (lT * rF);
			}
		}
		else if(S[k] == '^') {
			if(isTrue) {
				totalWay = totalWay  + (lT * rF) + (lF * rT);
			}
			else {
				totalWay = totalWay  + (lF * rF)  + (lT * rT);
			}
		}


	}
	return totalWay;
}





int main()
{

	int test,N;
	cin >> test;
	string S;
	while(test--) {
		cin >> N >> S;
		cout << countWays(S, 0, N-1, true) << endl;
		
	}

	return 0;

}

