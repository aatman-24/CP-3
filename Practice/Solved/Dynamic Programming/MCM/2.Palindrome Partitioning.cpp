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

Question : Palindrome Partitioning (MCM-Varints).
Topic : DP.
*/

// Here I optimized the code. But Its Still give TLE.
// for checking palindrome i need more to optimized. otherwise its work.



int t[501][501];
int p[501][501];

int isPalindrome(string S, int i, int j) {
	while(i <= j) {
		if(S[i] != S[j]) return 0;
		i++; j--;
	}
	return 1;
}

int palindromicPartition(string S, int i, int j) {

	if(t[i][j] != -1) return t[i][j];

	if(i > j) return INT_MAX;
	if(i == j) return t[i][j]=0;

	if(p[i][j] != -1) {
		if(p[i][j] == 1) return t[i][j]=0;
	}
	else {
		p[i][j] = isPalindrome(S, i, j);
		if(p[i][j] == 1) return t[i][j]=0;	
	}

	int min_op = INT_MAX;
	for(int k = i; k < j; k++) {

		int cost1 = (t[i][k] != -1) ? t[i][k] : palindromicPartition(S, i, k);
		t[i][k] = cost1; 

		int cost2 = (t[k+1][j] != -1) ? t[k+1][j] : palindromicPartition(S, k+1, j);
		t[k+1][j] = cost2;

		int tmp_cost = cost1  + cost2 + 1;
		min_op = min(min_op, tmp_cost);
	}

	return t[i][j]=min_op;
}

int main()
{

	int test;
	cin >> test;
	string S;
	while(test--) {
		memset(t, -1, sizeof(t));
		memset(p, -1, sizeof(p));
		cin >> S;
		cout << palindromicPartition(S, 0, (int)S.size() - 1) << endl;
	}

	return 0;

}

