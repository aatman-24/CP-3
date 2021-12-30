#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


// #Approach : Here we given the n dimension cubic so it has 2^n corner.We store the data into array 
// but for the calaculation apporach we use the bitmask.
// Two corner is neighbour if and only if only one dimension is change. (0,0,0) - (0,1,0) True
// but (0,1,1) -> (1,0,1) False.

// so we use the toggle bit opreation and change all the bit to find its neighbour.

// "int index = i ^ (1 << j)" (for change jth bit).


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vi result,arr;


	int n;
	while(cin >> n)
	{
		int k = (1 << n);
		result.assign(k,0);
		arr.assign(k,0);
		for(int i = 0 ; i < k ; i++) cin >> arr[i];

		for(int i = 0 ; i < k; i++)
		{
			for(int j = 0 ; j < n ;j++)
			{
				int index = i ^ (1 << j);
				result[i] += arr[index];
			}
		}

		int two_pair_sum = 0;
		for(int i = 0 ; i < k - 1 ; i++)
		{
			for(int p = 0 ; p < n ; p++)
			{
				int v = i ^ (1 << p);
				if (result[v] + result[i] > two_pair_sum) two_pair_sum = result[i] + result[v];
			}
		}

		cout << two_pair_sum << endl;
	}

	
	return 0;
}
