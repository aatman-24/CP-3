#include <bits/stdc++.h>
#include <iostream>
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
	

	// https://openology.blogspot.com/2013/08/how-i-solved-uva-12004-bubble-sort.html

	// Here we direct use => max_swaps/2;
	// max_swaps = n * (n-1) /2;

	ll denominator,max_swaps,min_num;
	ll case_n=1;
	int t; cin >> t;
	while(t--)
	{
		ll n; cin >> n;

		denominator = 2;

		max_swaps = n * (n - 1);

		denominator *= 2;

		if(max_swaps % (denominator) == 0)
		{
			cout << "Case " << case_n++ << ": " << max_swaps/(denominator) << endl;
		}
		else
		{
			min_num = 2;
			for(int i = min_num; i > 1; i--)
			{
				if(max_swaps % 2 == 0 && denominator % 2 == 0) {max_swaps /= 2; denominator /= 2;}
			}

			cout << "Case " << case_n++ << ": " << max_swaps << '/' << denominator << endl;

		}



	}	


	return 0;
}

