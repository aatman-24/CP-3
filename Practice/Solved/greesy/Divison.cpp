#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	



	int N;
	int abcde,temp,set;
	scanf("%d\n",&N);
	while(true)
	{
		if(N == 0) break;
		set = 1;		
		for(int fghij = 1234 ; fghij < 98765; fghij++)
		{
			abcde = fghij * N;
			if(abcde > 98765) continue; 
			int used = (fghij) < 10000; // Set 0000000001 (last bit if it is 0 than).
			
			temp = abcde; while(temp) {used |= (1 << temp % 10); temp /= 10;}
			temp = fghij; while(temp) {used |= (1 << temp % 10); temp /= 10;}


			if(used == ((1 << 10) - 1))
			{
				printf("%05d / %05d = %d\n", abcde, fghij, N);
				set = 0;
			}
		}
		if(set) printf("There are no solutions for %d.\n",N);
		scanf("%d\n",&N);
		if(N == 0) break;
		printf("\n");
	}
	return 0;
}