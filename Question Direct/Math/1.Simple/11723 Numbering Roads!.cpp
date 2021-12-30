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
	

	
	int R,N,case_n=1;
	while(1){
		scanf("%d %d\n",&R,&N);
		if(!(R || N)) break;

		if(N * 27 < R) printf("Case %d: impossible\n",case_n++);
		else{
			
			int i = 0;
			for(; i < 27; i++)
			{
				R -= N;
				if(R <= 0) break;
			}

			printf("Case %d: %d\n",case_n++,i);
		}
		
	}


	return 0;
}

