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


// #Approach : Here we just need to find max(dist of min dist between(1->3)).We need to check 
// all the (1,3) pairs.

// I try to solve this using grid. But I got TLE. Than I see there is no need to use grid.
// because it take O(N^3).

// Here we got it O(N*M).  N = number of 1, m = number of 3



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif



	vii ones_pos;
	vii three_pos;

	int n;
	char temp; 
	while(cin >> n)
	{
		ones_pos.clear();
		three_pos.clear();

		for(int i = 0 ; i < n  ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				cin >> temp;
				if(temp == '1') ones_pos.push_back({i,j});
				if(temp == '3') three_pos.push_back({i,j});
			}
		}
		
		int max_dist = INT_MIN;
		for(double i = 0 ; i < ones_pos.size() ; i++)
		{
			int min_dist = INT_MAX;
			for(double j = 0 ; j < three_pos.size() ; j++)
			{

				int dist = abs(ones_pos[i].first - three_pos[j].first) + abs(ones_pos[i].second - three_pos[j].second);
				if(min_dist > dist) min_dist = dist;
			}
			if(max_dist < min_dist) max_dist = min_dist;
		}


		cout << max_dist << endl;

	}
	return 0;
}



#grid method:


void grid_method()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int x[4] = {1, 0, -1, 0};
	int y[4] = {0, 1, 0, -1};

	vii ones_pos;
	vii three_pos;

	int xs,ys,xt,yt;
	int n; 
	while(cin >> n)
	{
		ones_pos.clear();
		three_pos.clear();
		vvc arr(n,vc(n,'0'));
		for(int i = 0 ; i < n  ; i++)
		{
			for (int j = 0 ; j < n ; j++)
			{
				cin >> arr[i][j];
				if(arr[i][j] == '1') 
				{
					ones_pos.push_back({i,j});
				}
				if(arr[i][j] == '3')
				{
					three_pos.push_back({i,j});
				}
			}
		}
		
		int temp_xs,temp_ys;
		int max_count = INT_MIN;
		for(double  i = 0 ;i < ones_pos.size(); i++)
		{
			temp_xs = ones_pos[i].first; temp_ys = ones_pos[i].second;
			int min_count = INT_MAX;
			for(double j = 0; j < three_pos.size() ; j++)
			{	
				xs = temp_xs; ys = temp_ys;
				xt = three_pos[j].first; yt = three_pos[j].second;
				int count = 0;
				while(!((xs == xt) && (ys == yt)))
				{
					for(int i = 0 ; i < 4 ; i++)
					{
						if((xs+x[i] < 0) || (ys+y[i] < 0)) continue;
						if((xs+x[i] >= n) || (ys+y[i] >= n)) continue;

						if((abs(xs - xt) > abs(xt - (xs + x[i]))) || (abs(ys - yt) > abs(yt - (ys + y[i]))))
						{
							xs = (xs + x[i]);
							ys = (ys + y[i]);
							count++;
						}
					}
				}
				if(min_count > count) min_count = count;
			};
			if(max_count < min_count) max_count = min_count;
		}

		cout << max_count << endl;
	}
}