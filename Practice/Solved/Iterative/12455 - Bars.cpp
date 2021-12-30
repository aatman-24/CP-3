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



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int len_req,n_bar,len_tmp,set;

	int t; cin >> t;

	while(t--)
	{
		cin >> len_req;
		cin >> n_bar;

		vi bars(n_bar,0);
		for(int i = 0; i < namespace_bar; i++) cin >> bars[i];

		set = 0;
		for(int i = 0 ;i < (1 << n_bar); i++)
		{
			len_tmp = 0;
			for(int k = 0; k < n_bar; k++)
			{
				int set_bit = (i & (1 << k));
				if(set_bit) len_tmp += bars[k];
			}
			if(len_tmp == len_req)
			{
				cout << "YES" << endl;
				set = 1;
				break;
			}
		}
		if(!set) cout << "NO" << endl;
	}




	return 0;

}