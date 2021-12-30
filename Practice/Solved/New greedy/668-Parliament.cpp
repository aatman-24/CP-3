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
	

	int m,n; cin >> m;
	vi arr;
	while(m--)
	{
		arr.clear();
		cin >> n;
		for(int i = 2 ; i <= n; i++)
		{
			arr.push_back({i});
			n -= i;
		}

		while(n)
		{
			for(int j = arr.size()-1; j > -1 && n > 0; j--)
			{
				arr[j] += 1;
				n--;
			}
		}


		for(double i = 0; i < arr.size() ; i++)
		{
			if(!i) cout << arr[i];
			else cout << ' ' << arr[i]; 
			// cout << arr[i] << ' ';
		}
		cout << endl;
		if(m) cout << endl;
	}

	return 0;
}

