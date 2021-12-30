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


int find_pos(vi &arr,int val)
{
	for(double i=0; i < arr.size() ; i++)
		if(arr[i] == val) return i;
	return -1;
}

// # Approach : Use two for loop and start from rare. Pick the element and
// check its pos in final error. if need to swipe the element than do it and count it.
// Here we used two for loop bcz n <= 24. so it is so easy to pass.


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int n;
	while(cin >> n)
	{
		vi start(n,0);
		vi end(n,0);

		for(int i = 0 ; i < n ; i++) cin >> start[i];
		for(int i = 0 ; i < n ; i++) cin >> end[i];


		int min_step = 0;


		for(int i = n - 1; i >= 0; i--)
		{

			int pos = find_pos(end,start[i]);
			for(int j = pos ; j < i; j++)
			{
				min_step++;
				int t = end[j];
				end[j] = end[j+1];
				end[j+1] = t; 
			}
		}

		cout << min_step << endl;

	}




	return 0;

}