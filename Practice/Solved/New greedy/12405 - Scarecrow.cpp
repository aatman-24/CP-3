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


// #Approach : we just need to put the scarecrawos at a specific field but using greedy Approach we identify
// that if given area is not covered then place it on next field so that next to next field also covered.
// and handle i = 0 and i = n - 1 separately.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int t,n; cin >> t;
	vector<char> fields;
	vector<int> result;
	int case_n = 1;
	while(t--)
	{
		cin >> n;
		fields.assign(n,'a');
		result.assign(n,0);
		for(int i = 0 ; i < n ; i++) cin >> fields[i];
		for(int i = 0 ; i < n ; i++)
		{
			if(fields[i] == '.')
			{
				if(i == 0) result[i+1] = 1;
				else if(i == n -1 && result[i - 1] != 1) result[i] = 1;  
				else if(result[i-1] != 1 && result[i] != 1) result[i+1] = 1; 
			}
		}
		cout << "Case " << case_n++ << ": " << accumulate(result.begin(),result.end(),0) << endl;

	}
	return 0;
}

