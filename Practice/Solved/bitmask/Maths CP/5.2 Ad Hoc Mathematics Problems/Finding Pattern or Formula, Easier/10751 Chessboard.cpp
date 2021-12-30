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


// diagonal distance is = (n - 2) ^ 2; for n > 1; I find this pattern.
// n = 1 -> 0 and distance also 0.
// n = 2 -> 0
// n = 3 -> 1
// n = 4 -> 4
// n = 5 -> 9
// so i decided maybe it's the pattern.


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int t; cin >> t;
	double ans;
	double diagonal, line;
	int N;
	while(t--)
	{
		cin >> N;
		if(N == 1) ans = 0;
		else
		{
			diagonal = (N - 2) * (N - 2);
			line = N * N - diagonal;
			ans = line + diagonal * sqrt(2);
		}
		printf("%.3f\n",ans);
		if(t) printf("\n");	
		
	}

	return 0;
}

