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

int a[12];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n,case_n=1;
	int t; cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0 ; i < n ; i++) cin >> a[i];

		// sort(a,a+n);

		cout << "Case " << case_n++ << ": " <<  a[n/2] << endl;
	}



	return 0;
}

