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

Question : Scrambled String (MCM-Varints).
Topic : DP.
*/

unordered_map<string,bool> mp;

string makeString(string a, string b) {
	return a + '_' + b ;
}

bool isScarmble(string a, string b) {

	string cc = makeString(a,b);

	if(mp.find(cc) != mp.end()) return mp[cc];
	if(a.compare(b) == 0) return true;
	if(a.length() <= 1) return false;

	int n = (int)a.size();

	bool flag = false;
	for(int i = 1; i < n; i++) {

		bool x1 =  isScarmble(a.substr(0,i), b.substr(0,i)) && isScarmble(a.substr(i,n-i), b.substr(i,n-i));
		bool x2 =  isScarmble(a.substr(0,i), b.substr(n-i,i)) && isScarmble(a.substr(i,n-i), b.substr(0,n-i));

		if(x1 || x2)
		{
			flag = true;
			break;
		}

	}
	return mp[cc] = flag;
	
}



int main()
{

	int test,N;
	cin >> test;
	string X, Y;
	while(test--) {

		mp.clear();
		cin >> X >> Y;
		if(X.length() != Y.length()) return 0;
		else 
			cout << isScarmble(X,Y) << endl;
		
	}


	return 0;

}

