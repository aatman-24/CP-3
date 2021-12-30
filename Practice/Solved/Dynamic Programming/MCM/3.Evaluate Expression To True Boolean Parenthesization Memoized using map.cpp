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

// int t[201][201][2];
unordered_map<string,int> mp;


string getString(int i,int j, int isTrue) {
	return to_string(i) + to_string(j) + to_string(isTrue);
}


int countWay(string S, int i, int j, bool isTrue) {

	if(i > j) return 0;


	string tmp_str = getString(i,j,isTrue);

	if(mp.find(tmp_str) != mp.end()) return mp[tmp_str];
	// if(t[i][j][isTrue] != -1) return t[i][j][isTrue];

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

    		int lT = (mp.find(getString(i,k-1,true))!= mp.end()) ? mp[getString(i,k-1,true)] : countWay(S, i, k-1, true);
    		mp[getString(i,k-1,true)] = lT;


    		int lF = (mp.find(getString(i,k-1,false))!= mp.end()) ? mp[getString(i,k-1,false)] : countWay(S, i, k-1, false);
    		mp[getString(i,k-1,false)] = lT;


    		int rT = (mp.find(getString(k+1,j,true))!= mp.end()) ? mp[getString(k+1,j,true)] : countWay(S, k+1,j, true);
    		mp[getString(k+1,j,true)] = rT;


    		int rF = (mp.find(getString(k+1,j, false))!= mp.end()) ? mp[getString(k+1,j,false)] : countWay(S, k+1,j false);
    		mp[getString(k+1,j,false)] = rF;

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
	return mp[tmp_str] = totalWay;
}



    
    


int main()
{

	int test,N;
	cin >> test;
	string S;
	while(test--) {
		mp.clear();
		cin >> N >> S;
		cout << countWay(S, 0, N-1, true) << endl;

	}

	return 0;

}

