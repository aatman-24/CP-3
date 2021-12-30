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
	
	int max_people,rem_co,ans;
	
	int N;
	while(cin >> N)
	{
		if(N <= 0) break;

		max_people = sqrt(N-1) + 1;
		ans = 0;
		for(int i = max_people; i >= 2; i--)
		{
			rem_co = N;
			int j = 0;
			for(; j < i; j++)
			{
				if(rem_co % i != 1) break;
				rem_co -= (rem_co / i + 1);
			}
			if(j == i && rem_co % i == 0) {ans = i; break;}

		}
		if(ans)
		{
			cout << N << " coconuts, " << ans << " people and 1 monkey\n";
		}
		else
		{
			cout << N << " coconuts, no solution" << endl;
		}
	}



	return 0;
}

