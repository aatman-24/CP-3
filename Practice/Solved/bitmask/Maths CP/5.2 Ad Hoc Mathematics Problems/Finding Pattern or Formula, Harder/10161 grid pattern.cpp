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
	

	vector<ll> diagnoal;
	ll previous_value = 1;
	ll n = 0;

	while(previous_value <= 2 * pow(10,9))
	{
		previous_value += (2*n);
		n++;
		diagnoal.push_back(previous_value);
	}

	int N,X,Y;

	while(cin >> N)
	{
		if(N == 0) break;
		int j = 0;
		while(diagnoal[j] <= N) j++;
		int point = diagnoal[j-1];

		if(point == N) cout << j << ' ' << j << endl;
		else
		{
			if((point < N) && (N <= (point + j - 1)))
			{
				if(j % 2 == 0)
				{
					X = j;
					while(point != N) {j--; point++;}
					Y = j;
				}
				else
				{
					Y = j;
					while(point != N) {j--; point++;}
					X = j;
				}
			}
			else
			{
				j++;
				point = diagnoal[j-1];
				if(j % 2 != 0)
				{
					X = j;
					while(point != N) {j--; point--;}
					Y = j;
				}
				else
				{
					Y = j;
					while(point != N) {j--; point--;}
					X = j;
				}
			}
			cout << X << ' ' << Y << endl;
		}
	}

	return 0;
}

