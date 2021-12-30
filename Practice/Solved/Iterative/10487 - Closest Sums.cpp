#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,m;
	vi arr;

	int query,differnce;
	int t = 0;

	while(cin >> n)
	{
		if(n == 0) break;
		t++;
		arr.assign(n,0);


		for(int i = 0 ; i < n ; i++) cin >> arr[i];
		sort(arr.begin(),arr.end());
		cin >> m;

		cout << "Case " << t << ":\n";
		for(int k = 0 ; k < m ; k++)
		{
			cin >> query;
			differnce = query - (arr[0] + arr[1]);
			int ans = arr[0] + arr[1];

			for(int i = 0 ; i < n; i++)
			{
				if (arr[i] >= query) break;
				for(int j = i + 1; j < n; j++)
				{ 
					int sum_val = query -  (arr[i] + arr[j]);
					if(abs(sum_val) < abs(differnce)) {
						differnce = abs(sum_val);
						ans = arr[i] + arr[j];

						
					}
				}
			}

			cout << "Closest sum to " << query << " is " << ans  << '.' << endl;
		}
	}

	return 0;

}