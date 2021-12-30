#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;

bitset<22> M;
int n,m,k,actualArea,size;

int count_of_set_bits(int num)
{
	M = num;
	return M.count();	
}

void printLocations(int Locations) {
    for (int i=0 ; i<n ; i++) 
    {
    	if(Locations & (1 << i))  printf(" %d",i+1);
    }
}

bool check_for_1_2(int a,int b)
{
	// if((a & (1 << (n - 1))) != 1 | a & (1 << (n-2)) != 1)
	

	// check a is contain 1st|2nd or pos.
	
	// if(b > n) return false;

	printf("%d - %d - %d - %d\n", (1 << (n-1)),a,b,n );

	if((a & 1 << (n-1)) && a > b) 
	{
		printf("iam1\n");
		return false;
	}

	if((b & 1 << (n-1)))
	{
		printf("iam2\n");
		 return true;
	}

	if((a & 1 << (n-2)))
	{
		printf("iam3\n");
		return false;
	} 

	printf("iam4\n");
	return true;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int index,value;
	int max_area,bestLocation;
	map<int,int> mii;

	
	// int bestLocation;
	int test_case = 1;
	while(cin >> n >> k)
	{

		if(n == 0 && k == 0) break;
		mii.clear();
		vi arr(n,0);
		for(int i = 0 ; i < n; i++) cin >> arr[i];

		cin >> m;
		while(m--)
		{
			cin >> size;
			int key = 0;
			for(int i = 0 ; i < size; i++)
			{
				cin >> index;
				key |= (1 << (index - 1));
			}
			
			cin >> value;
			mii[key] = value;
		}


		max_area = INT_MIN;

		for(int perm = 0 ; perm < (1 << n); perm++)
		{
			actualArea = 0;
			if(count_of_set_bits(perm) == k)
			{
				for (int i=0 ; i<n ; i++) 
				{
	                if (perm & (1 << i)) 
	                {
	                    actualArea += arr[i];
                	}
            	}


            	// now try to get intersection and remove it.


            	for(auto i:mii)
            	{
            		int how_many_set = count_of_set_bits(i.first & perm);
            		if(how_many_set >= 2)
            		{
            			actualArea -= ((how_many_set-1) * i.second);
            		}
            	}


       			if(actualArea > max_area))
       			{
       				max_area = actualArea;
       				bestLocation = perm;
       			}

			}

		}

		printf("Case Number  %d\n", test_case++);
        printf("Number of Customers: %d\n", max_area);
        printf("Locations recommended:"); printLocations(bestLocation);
        printf("\n\n");






	}



	return 0;

}