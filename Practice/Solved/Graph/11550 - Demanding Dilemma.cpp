#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


void display(vector<int> &vec)
{
	for (double i = 0; i < vec.size(); i++)
	{
		cout << vec[i] <<  ' ';
	}
	cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vector<int> sumofnum;
	int n,m;
	string s; 
	int t,num; cin >> t;
	
	while(t--)
	{	
		cin >> n >> m;
		if(m == 0)
		{
			for(int i = 0;i <= n; i++) getline(cin,s);
			cout << "Yes" << endl;
			continue;
		}
		vector<int> node_count(m,0);
		vector<vector<int>> vvi;

		for(int i = 0 ; i < m; i++)
		{
			vector<int> v;
			vvi.push_back(v);
		}

		for(int i = 0 ;i < n ; i++)
		{
			for(int j = 0 ; j < m ; j++)
			{
				cin >> num;
				node_count[j] += num;
				if(num != 0) vvi[j].push_back(i+1);
				
			}
		}

		int set = 0;

		for(int index = 0 ; index < m ;index++)
		{
			if((node_count[index] % 2 != 0) || (node_count[index] > 2)) set = 1;
		}

		if(set == 0)
		{
			for(int index = 0 ; index < m ;index++)
			{
				sumofnum.push_back(vvi[index][0] * 100 + vvi[index][1]);
			}

			sort(sumofnum.begin(),sumofnum.end());

			for(double i = 1 ; i < sumofnum.size() ;i++)
			{
				if(sumofnum[i-1] == sumofnum[i])
				{
					set = 1;
					break;
				}
			}
			
		}
	
		if(set) cout << "No" << endl;
		else cout << "Yes" << endl;

		vvi.clear();
		node_count.clear();
		sumofnum.clear();

	}
	return 0;

}