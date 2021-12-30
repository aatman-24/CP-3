#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>



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
			
	int n;
	vi arr;
	
	while(cin >> n)
	{
		if(!n) break;
		arr.assign(n,0);

		for(int i = 0 ; i < n ; i++) cin >> arr[i];

		int sum_va = (accumulate(arr.begin(),arr.end(),0));
		if(sum_va == 0) cout << '0';
		else{
			int flag = 0;
			for(int i = 0; i < n ; i++)
				if(arr[i] > 0)
				{
					if(flag) cout << ' ' << arr[i]; 
					else {cout << arr[i]; flag = 1;}
				}
		}
		cout << endl;
		
	}


	return 0;
}

