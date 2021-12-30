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
	
	int t; cin >> t;
	double A,B,C;
	for(int case_n=1; case_n<=t; case_n++)
	{
		cin >> A >> B >> C;

		ll extra = (A + B + C) - 100;
		extra = ceil((double)extra/2);

		ll mnn = max((ll)0,extra);
		ll mxx = min(A,min(B,C));

		cout << "Case #" << case_n << ": "; 
		if(mnn > mxx) cout << "The records are faulty." << endl;
		else cout << "Between " << mnn << " and " << mxx << " times." << endl;

	}

	



	return 0;
}

