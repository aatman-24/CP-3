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


// #Approach : If first_day = 1, then sequence is 1 2 3 4 5 6 7 ...... increase the member like this..

// It's means day which assigned the group is like 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5... like this...

// we can get the n of above sequence using n * (n + 1) / 2 = given days.

// and if first_day != 1 at a time we have to subtract the days from the total days...

// like -> 3...n = 1...n - 1..2 and,

// so final equation ...

// m = start_day - 1;

// group_memeber = n * (n + 1) / 2 - m * (m + 1) / 2 >= given_day (whichever occur first)

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
	
	ll s_day,day;

	while(cin >> s_day >> day)
	{
		ll before_day_sum = (s_day - 1) * (s_day) / 2;

		ll n = 1;
		while(n * (n + 1) - 2 * before_day_sum < (2 * day)) n++;
		cout << n << endl;
	}	



	return 0;
}

