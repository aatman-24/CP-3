#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define ll long long

using namespace std;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int a,b,c;
	vector<int> vi;

	int N; scanf("%d\n",&N);
	while(N--)
	{
		scanf("%d %d %d\n",&a,&b,&c);
		int set = 0;
		for(int i = -22 ;i < 22 && !set; i++)   // XYZ = B
		{
			if(i * i > c) continue;
			for(int j = -100 ; j < 100 && (!set) ; j++) // x*x+y*y+z*z = A
			{
				if((i==j)  | (i * i + j * j > c)) continue;
				for(int k = -100 ; k < 100 ;k++) // x + y + z = c
				{
					if(i != j && j != k && k != i && i+j+k == a && i*j*k==b && i*i+j*j+k*k==c && (!set))
					{
						vi = {i,j,k};
						sort(vi.begin(),vi.end());
						set = 1;
						printf("%d %d %d\n",vi[0],vi[1],vi[2]);
					}
				}		
			}
		}
		if(!set) printf("No solution.\n");
	}


	return 0;

}