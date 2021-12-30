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
	

	int N, sum_of_componet;
	printf("PERFECTION OUTPUT\n");
	while(cin >> N)
	{
		if(!N) break;

		sum_of_componet = 0;
		for(int i = 2; i <= N; i++)
		{
			if(N % i == 0) sum_of_componet += (N/i);
		}

		if(sum_of_componet < N) 
		{
			printf("%5d DEFICIENT\n",N);
		}
		else if(sum_of_componet == N)
		{
			printf("%5d PERFECT\n",N);
		}
		else
		{
			printf("%5d ABUNDANT\n",N);
		}

	}
	printf("END OF OUTPUT\n");



	return 0;
}

