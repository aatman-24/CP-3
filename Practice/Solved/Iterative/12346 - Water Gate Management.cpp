#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


// #Approach : Here we given (1 <= n <= 20).Given V to find is in given hours but we have data
// in 1 hrs. so we make it V_per_hour than try to find using all combination.
// Bcz n <= 20 -> 2^20 -> 10^6 so still is possible in O(N).


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	double V,T,V_per_hour,cost_tmp,V_temp;

	int n_watergates; 
	cin >> n_watergates;
	vi flow(n_watergates,0);
	vi cost(n_watergates,0);
	for(int i = 0 ; i < n_watergates ; i++) cin >> flow[i] >> cost[i];

	int m; cin >> m;
	for(int j = 0; j < m; j++)
	{
		cin >> V >> T;
		V_per_hour = (V / T);

		double min_cost = INT_MAX;

		for(int i = 0; i < (1 << n_watergates); i++)
		{
			cost_tmp = 0;
			V_temp = 0;

			for(int k = 0; k < n_watergates; k++)
			{

				int set_bit = (i & (1 << k));
				if(set_bit)
				{
					V_temp += flow[k];
					cost_tmp += cost[k];
				}
				
			}


			if((V_temp >= V_per_hour) && (cost_tmp < min_cost)) min_cost = cost_tmp;
		}

		if(min_cost == INT_MAX) cout << "Case " << j+1 << ": " << "IMPOSSIBLE" << endl;
		else cout << "Case " << j+1 << ": " << min_cost << endl;

	}


	
	return 0;

}