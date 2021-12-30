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

vvi raws;
int N,M,Q,L,U;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	while(cin >> N >> M)
	{
		if(N == 0 && M == 0) break; 
		raws.assign(N,vi(M,0));

		for(int i = 0; i < N ; i++)
			for(int j = 0; j < M; j++)
				cin >> raws[i][j];
			
		
		cin >> Q;
		while(Q--)
		{	
			cin >> L >> U;
			int max_dist = INT_MIN;
			for(int i = 0 ; i < N; i++)
			{
				int l_raw = lower_bound(raws[i].begin(),raws[i].end(),L) - raws[i].begin();
				if(l_raw > M) continue;

				int cur_step = 0;
				int j = i;
				while(j < N && l_raw < M && raws[j][l_raw] <= U)
				{
					cur_step++;
					j++;
					l_raw++;
				}
				if(cur_step > max_dist) max_dist = cur_step;
			}
			cout << max_dist << endl;
		}
		cout << '-' << endl;
	}
	return 0;
}

