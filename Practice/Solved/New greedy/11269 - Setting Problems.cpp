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

bool sort_Fun(ii p1, ii p2)
{
	if(p1.second > p2.first && p2.second > p1.first) return p1.first < p2.first;
	if(p1.second > p2.first) return p2.second < p2.first;
	if(p2.second > p1.first) return p1.first < p1.second;
	return p2.second < p1.second;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vi setter, tester;
	vii values;
	int n;
	while(cin >> n)
	{
		values.assign(n,{0,0});
		tester.assign(n,0);
		setter.assign(n,0);

		for(int i = 0 ; i < n ; i++) cin >> setter[i];
		for(int i = 0 ; i < n ; i++) cin >> tester[i];
		for(int i = 0 ; i < n ; i++) values[i] = {setter[i],tester[i]};


		sort(values.begin(),values.end(),sort_Fun);

		int c_t = 0,r_t = 0;
		for(int i = 0; i < n ;i++)
		{
			c_t += values[i].first;
			r_t = max(r_t,c_t) + values[i].second;
		}

		cout << r_t << endl;


	}



	return 0;
}



// a b
// c d      a -> smallest  c-> bigger b->bigger d-> smallest if(c > b)
// 		 a -> biggest   c-> smalles b->smallest d->bigger if(d > a)
