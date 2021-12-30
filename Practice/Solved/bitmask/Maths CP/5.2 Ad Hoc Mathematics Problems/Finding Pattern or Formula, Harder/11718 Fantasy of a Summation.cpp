#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


// pattern which i find is = K * (N ^ K-1).

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int N,K,MOD,sum_of_elements,tmp;
	int t; cin >> t;
	for(int case_n = 1; case_n <= t; case_n++)
	{
		cin >> N >> K >> MOD;
		sum_of_elements = 0;
		for(int i = 0 ; i < N; i++) {cin >> tmp; sum_of_elements += tmp;}
		int result = (int)((pow(N,K-1) * K) * sum_of_elements);
		cout << "Case " << case_n << ": " << result % MOD  << endl;

	}	





	return 0;
}

