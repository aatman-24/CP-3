#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef map<int,vector<int>> mivi;

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
	

	int n,m;
	int num;
	double k_th_occur,v;
	map<int,vector<int>> num_pos_map; 
	while(cin >> n)
	{	
		if(n == EOF) break;
		cin >> m;
		num_pos_map.clear();
		for(int i = 0 ; i < n ; i++)
		{
			cin >> num;
			if(num_pos_map.find(num) == num_pos_map.end())
			{
				num_pos_map[num] = {i+1};
			}
			else 
			{
				num_pos_map[num].push_back(i+1);
			}

		}

		for(int i= 0 ; i < m ; i++)
		{
			cin >> k_th_occur >> v;
			if(k_th_occur <= num_pos_map[v].size())
			{
				cout << num_pos_map[v][k_th_occur-1] << endl;
			}
			else cout << "0\n"; 
		}


	}
	return 0;

}