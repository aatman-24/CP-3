#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int a,b,c,e;
	int t; cin >> t;
	while(t--)
	{
		cin >> a >> b >> c;

		e = c * (a + (a - b)) / (a + b);  

		if(e <= 0) cout << '0' << endl;
		else cout << e << endl;

	}
	

	return 0;
}

