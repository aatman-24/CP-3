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


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
		
	int N,x,y,up;

	while(cin >> N)
	{
		x = 1, y = 1;
		up = 1;
		int N_OG = N;
		while(N) 
		{
			if(up)
			{
				while(x && N){
					N--;
					if(N) {x--;y++;}
				}
				up = 0;
				if(N) x++;
			}
			else
			{
				while(y && N){
					N--;
					if(N){x++;y--;}
				}
				up = 1;
				if(N) y++;
			}
		}
		printf("TERM %d IS %d/%d\n",N_OG,x,y);
	}
	



	return 0;
}

