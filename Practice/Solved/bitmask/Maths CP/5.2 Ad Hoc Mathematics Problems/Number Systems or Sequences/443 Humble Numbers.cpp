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


ll power(int base, int n)
{
	if(n == 0) return 1;
	
	ll ans = power(base,n/2);
	ans *= ans;
	if(n % 2 == 1) ans *= base;
	return ans;
}

ll base_number[4] = {2,3,5,7};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	set<ll> st;
	st.insert(1);

	set<ll>::iterator i = st.begin();
	while(st.size() <= 6600)
	{
		for(int j = 0; j < 4; j++)
		{
			st.insert((*i)*(base_number[j]));
		}
		i++;
	}

	vector<ll> arr(st.begin(),st.end());
	string s;
	int n;
	while(cin >> n)
	{
		if(!n) break;
		if (n % 100 == 11 || n % 100 == 12 || n % 100 == 13) s = "th";
        else if (n % 10 == 1) s = "st";
        else if (n % 10 == 2) s = "nd";
        else if (n % 10 == 3) s = "rd";
        else s = "th";
        cout << "The " << n << s << " humble number is " << arr[n-1] << ".\n";
	}

	return 0;
}

