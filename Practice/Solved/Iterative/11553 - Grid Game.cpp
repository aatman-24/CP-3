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
typedef vector<vi> vvi;



void display(vvi &arr)
{
	for(double i = 0 ; i < arr.size() ; i++)
	{
		for(double j = 0 ; j < arr.size() ; j++)
			cout << arr[i][j] << ' ';
		cout << endl;
	}
		
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;

		vvi arr(n,vi(n,0));

		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < n ; j++)
				cin >> arr[i][j];


		// display(arr);

		vi perm_arr(n,0);
		for(int i = 0 ; i < n ; i++) perm_arr[i] = i;

		int min_value = INT_MAX;

		do
		{
			int cost = 0;
			for(int f_index = 0 ; f_index < n; f_index++)
			{
				cost += arr[f_index][perm_arr[f_index]];
			}
			if(cost < min_value) min_value = cost;
		}while(next_permutation(perm_arr.begin(),perm_arr.end()));

		cout << min_value << endl;

		// break;
	}



	return 0;

}