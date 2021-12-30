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

int t[201][201][2];
int countWay(string S, int i, int j, bool isTrue) {

	if(i > j) return 0;

	if(t[i][j][isTrue] != -1) return t[i][j][isTrue];

	if(i == j) {
		if(isTrue) {
			return t[i][j][isTrue] =  S[i] == 'T' ? 1 : 0;
		}
		else {
			return t[i][j][isTrue] =  S[i] == 'F' ? 1 : 0;
		}
	}

	int totalWay = 0;
	for(int k = i + 1; k < j; k+=2) {

		int lT,lF,rT,rF;

		if(t[i][k-1][true] != -1) {
			lT = t[i][k-1][true];
		}
		else {
			lT = countWay(S, i, k-1, true);
			t[i][k-1][true] = lT;
		}

		if(t[i][k-1][false] != -1) {
			lF = t[i][k-1][false];
		}
		else {
			lF = countWay(S, i, k-1, false);
			t[i][k-1][false] = lF;
		}


		if(t[k+1][j][true] != -1) {
			rT = t[k+1][j][true];
		}
		else {
			rT = countWay(S, k+1, j, true);
			t[k+1][j][true] = rT;
		}

		if(t[k+1][j][false] != -1) {
			rF = t[k+1][j][false];
		}
		else {
			rF = countWay(S, k+1, j, false);
			t[k+1][j][false] = rF;
		}


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
	return t[i][j][isTrue] = (totalWay % 1003);
}

int main()
{

	int test,N;
	cin >> test;
	string S;
	while(test--) {
		memset(t, -1, sizeof(t));
		cin >> N >> S;
		cout << countWay(S, 0, N-1, true) << endl;
		
	}

	return 0;

}

