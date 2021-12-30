#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
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
	

	int t; cin >> t;
	int n;
	int c;
	while(t--)
	{
		cin >> n;
		vi arr(n,0);
		int total = 0;
		for (int i = 0; i < n; i++) cin >> arr[i];
		for (int i = 1; i < n ; i++)
		{
			c = 0;
			for(int  j = i - 1  ; j >= 0 ; j--)
			{
				if(arr[j] <= arr[i]) c++;
			}
			total += c;
		}
		cout << total << endl;
	}


	return 0;

}