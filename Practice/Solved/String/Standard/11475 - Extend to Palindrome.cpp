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

Question : 11475 - Extend to Palindrome
Topic : String , kmp
Problems :
*/

int prefix_table[1000005];

void kmpTable(string p) {
	int m = p.size();
 	int pt = -1, index = 0;
	prefix_table[0] = -1;
	while(index < m) {
		while(pt >= 0 && p[index] != p[pt]) pt = prefix_table[pt];
		pt++; index++;
		prefix_table[index] = pt;
	}
}


int kmp(string st, string p) {
	kmpTable(p);
	int i = 0, j = 0, m = st.size();
	while(i < m) {
		while(j >= 0 && st[i] != p[j]) j = prefix_table[j];
		i++; j++;
	}
	return j;
}

int main() {
	string s, pattern;
	while(cin >> s) {
		pattern = s;
		reverse(pattern.begin(), pattern.end());
		memset(prefix_table, 0, sizeof(prefix_table));
		int m = s.size();
		int i = kmp(s, pattern);
		while(i <= m - 1){
			s += pattern[i];
			i++;
		}
		cout << s << endl;
	}
	return 0;
}
