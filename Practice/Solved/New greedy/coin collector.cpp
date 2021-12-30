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
	
	vi arr;
	int t,n; cin >> t;
	while(t--)
	{
		cin >> n;
		arr.assign(n,0);
		for(int i = 0; i < n;i++) cin >> arr[i];
			
		int diff_coin = 0;
		int sum = 1;
		for(int i = 1; i < n-1; i++)
		{
			if(sum + arr[i] < arr[i+1]) {sum += arr[i]; diff_coin++;}
		}

		cout << diff_coin+2 << endl;
	}


	return 0;
}

