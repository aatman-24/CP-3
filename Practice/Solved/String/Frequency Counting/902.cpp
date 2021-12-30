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



int main() {

	int K;
	string S;
	map<string,int> mp;
	while(cin >> K) {
		cin >> S;
		int N = S.size();
		mp.clear();

		for(int i = 0; i <= N - K; i++) {
			string nw_str ="";
			for(int j = i; j < i+K; j++) {
				nw_str += S[j];
			}
			if(mp.find(nw_str) == mp.end()) mp[nw_str] = 1;
			else mp[nw_str]++;
		}

		string ans;
		int mx_occ = INT_MIN;
		for(auto i : mp) {
			if(i.second > mx_occ) {
				mx_occ = i.second;
				ans = i.first;
			}
		}

		cout << ans << endl;

	}

}


// thearraycanbetoobigsobecarefulandtherecantberarecasescanbe
