
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


typedef vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;

void display(vi &arr)
{
	for(double i = 0 ; i < arr.size() ; i++) {cout << arr[i] << ' ';}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n,m;
	int a,b,c;
	while(cin >> n >> m)
	{
		if(n == 0 &&  m == 0) break;
		vector<int> arr(n,0);
		for(int i = 0 ; i < n ; i++ ) arr[i] = i;

		ii temp;
		AdjList store(9,vii(9,temp));

		for(int i = 0 ; i < m ; i++)
		{
			cin >> a >> b >> c;
			store[a].push_back({b,c});
		}
		
		int counter = 0 ;
		do
		{
			// check constraint is follow or not
			// display(arr);
			int valid = 1;
			for(int i = 0 ; i < n && valid; i++)
			{
				int in_size = store[arr[i]].size();
				if(in_size > 0)
				{
					for(int j = 0 ; j < in_size && valid ; j++)
					{
						int dist = store[arr[i]][j].second;
						int second_num = store[arr[i]][j].first;
						int second_num_index;
						for(int k = 0 ; k < n ; k++)
						{
							if(arr[k] == second_num)
								second_num_index = k;
						}
						if(dist <= 0)
						{
							if(abs(i - second_num_index) >= abs(dist)) continue;
							else {valid = 0; break;}
						}
						else
						{
							if(abs(i - second_num_index) <= abs(dist)) continue;
							else {valid = 0; break;}
						}
					}
				}
			}
			if(valid) counter++;
		}while(next_permutation(arr.begin(),arr.end()));

		cout << counter << endl;
	}


	return 0;
}