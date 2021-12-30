#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl;
#define mod 1000000007

using namespace std;


typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef map<int,int> mii;

/*
==============================> Description <=============================================

Question : KMP
Topic : 
Problems :
*/


map<char,int> mp1, mp2;

string solve(string s1, string s2) {

	mp1.clear(); mp2.clear();
	int n = s1.size();
	int m = s2.size();

	sort(s1.begin(), s1.end());

	for(int i = 0; i < n; i++) {

		if(i > 0 && s1[i-1] == s1[i]) continue;

		int cnt1 = 0;
		for(int k = 0; k < n; k++) {
			if(s1[i] == s1[k]) cnt1++;
		}
		mp1[s1[i]] = cnt1;

		int cnt = 0;
		for(int j = 0; j < m; j++) {
			if(s1[i] == s2[j]) cnt++;
		}
		mp2[s1[i]] = cnt;
	}


	string res = "";
	for(auto i : mp1) {
		if(mp2.find(i.first) != mp2.end()) {
			int occ = min(i.second, mp2[i.first]);
			for(int cnt = 0; cnt < occ; cnt++) res += i.first;
		}
	}

	return res;

}

	
int main() {
	string s1, s2;
	while(getline(cin,s1)) {
		getline(cin,s2);
		if(s1.size() < s2.size()) {
			cout << solve(s1,s2) << endl;
		}
		else {
			cout << solve(s2,s1) << endl;
		}
	}	

}
