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
	

	vi freq_count;
	int t; cin >> t;
	int N;
	while(t--)
	{
		cin >> N;
		freq_count.assign(10,0);
		for(int i = 1; i <= N; i++)
		{
			if(i <= 9) freq_count[i]++;
			else
			{
				freq_count[i%10]++;
				freq_count[i/10]++;
			}
		}

		for(int i = 0; i <= 9; i++) cout << freq_count[i] << ' ';
		cout << endl;
	}



	return 0;
}

