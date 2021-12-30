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

Question : 455 Periodic Strings
Topic : String , kmp
Problems :
*/

/*

What KmpTable do you know ? -> This match the prefix and suffix of the string.

abcabc -> 0 0 0 1 2 3. (when the continuous seq 123 represet the 3 length prefix is matched with cur string).

So Here we used same logic if any pattern is repeated into the given S. Then the last index of 

KmpTable must be valid number such that (m - kmp[m]) must divide the all string.

it means that (m - kmp[m]) -> length of this pattern.

and if not then there is no pattern in the string s then we return length of s.


*/

void kmpTable(string p, int tb[]) {
	int m = p.size();
 	int pt = -1, index = 0;
	tb[0] = -1;
	while(index < m) {
		while(pt >= 0 && p[index] != p[pt]) pt = tb[pt];
		pt++; index++;
		tb[index] = pt;
	}
}

int main() {

	int t; cin >> t;
	string p;
	while(t--) {
		cin >> p;
		int m = p.size();
		
		if(m <= 1) {
			cout << m << endl;
		}
		else {

			int tb[m+1];
			kmpTable(p, tb);


			if(m % (m - tb[m]) == 0) {
				cout << m - tb[m] << endl;
			}
			else{
				cout << m << endl;
			}
		}		
		if(t != 0) cout << endl;
	}
}