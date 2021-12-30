#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


// #Approach : Here we just need to see given letters is repeat in last k occurs.if we use normal
// array or something than it is still okay -> O(k*N).


// I used map so it is just O(N).



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	map<char,int> mci;



	int t; cin >> t;
	int n,k;
	string letters;

	for(int i = 0; i < t; i++)
	{

		mci.clear();
		cin >> n >> k;
		cin >> letters;


		double size = letters.size();
		int c = 0;

		for(int i = 0; i < size; i++)
		{
			if(mci.find(letters[i]) == mci.end())
			{
				mci[letters[i]] = i;
			}
			else 
			{
				if(i - mci[letters[i]] <= k) c++;
				mci[letters[i]] = i; 
			}

		}

		cout << "Case " << i+1 << ": " << c << endl; 

	}


	return 0;

}