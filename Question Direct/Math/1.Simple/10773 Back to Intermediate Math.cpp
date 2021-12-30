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
	

	double d,v,u;
	int t; scanf("%d\n",&t);
	int case_n = 1;
	while(t--)
	{
		scanf("%lf %lf %lf\n",&d,&v,&u);

		if(u == 0 || v == 0 || u <= v) printf("Case %d: can't determine\n",case_n++);
		else
		{
			double result = abs((d/u) - (d/sqrt(u*u - v*v)));
			printf("Case %d: %.3lf\n",case_n++,result);
		}
	}


	return 0;
}

