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

Question : 10298 - Power Strings
Topic : String , kmp
Problems :
*/

/*

What KmpTable do you know ? -> This match the prefix and suffix of the string.

abcabc -> 0 0 0 1 2 3. (when the continuous seq 123 represent the 3 length prefix is matched with cur string).


Here we give s and need to find pattern a such that a^n (n is maximum).

In simple language we need to find smallest repetable pattern into s and return the how many time it repeat.


same as 455, Used KMP,

kmp[lastIndex] represent the continous value which matched prefix.

So Here we used same logic if any pattern is repeated into the given S. Then the last index of 

KmpTable must be valid number such that (m - kmp[m]) must divide the string length.

it means that (m - kmp[m]) -> length of this pattern.

so total time pattern occur in S is = m / (m - kmp[m]).

and if not then there is no pattern in the string s then we return 1. (og string).


*/

int kmpTable(string p ) {
	int m = p.size();
	int tb[m + 1];
 	int pt = -1, index = 0;
	tb[0] = -1;
	while(index < m) {
		while(pt >= 0 && p[index] != p[pt]) pt = tb[pt];
		pt++; index++;
		tb[index] = pt;
	}
	return pt;
}

int main() {


	string p;
	while(cin >> p) {
		if(p == ".") break;
		int m = p.size();
		if(m <= 1) {
			cout << m << endl;
		}
		else {

			int lastptValue = kmpTable(p);

			if(m % (m - lastptValue) == 0) {
				cout << m / (m - lastptValue) << endl;
			}
			else{
				cout << 1 << endl;
			}
		}		

	}
}