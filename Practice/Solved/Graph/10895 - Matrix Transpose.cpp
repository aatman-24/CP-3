#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


void display(vector<vii> &AdjList)
{
	int n = int(AdjList.size());
	cout << n << endl;
	for (int i = 0 ; i < n ;i++)
	{
		int m = int(AdjList[i].size());
		for(int j = 0 ; j < m ;j++)
		{
			cout << '[' << i+1 << ',' << AdjList[i][j].first+1 << ']' << "-----" << AdjList[i][j].second << endl;
		}
	}
}



void display_vec(vector<int> vec)
{
	for (double i = 0 ; i < vec.size() ;i++)
	{
		cout << vec[i] << ' ';
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


	int n,m,ith_index_total_num,value_of_i_j,index;
	string temp_str;
	vector<int> col_indexs;



	while(cin >> n >> m)
	{

		AdjList.clear();
		for (int i = 0 ;i < m ;i++)
		{
			vector<ii> temp;
			AdjList.push_back(temp);
		}

		for(int i = 0; i < n;i++)
		{

			cin >> ith_index_total_num;
			if(ith_index_total_num == 0)
			{
				getline(cin,temp_str);
				getline(cin,temp_str);
			}
			else
			{
				col_indexs.clear();
				for(int col_ind = 0 ; col_ind < ith_index_total_num; col_ind++)
				{
					cin >> index;
					col_indexs.push_back(index-1);
				}
				for(int col_ind = 0 ; col_ind < ith_index_total_num; col_ind++)
				{
					cin >> value_of_i_j;
					AdjList[col_indexs[col_ind]].push_back({i,value_of_i_j});
				}
			}
		}



		// display(AdjList);



		// formating output - sparse matrix


		cout << m << ' ' << n << endl;
		for (int i = 0 ; i < m ;i++)
		{
			int n = int(AdjList[i].size());
			if(n == 0) cout << "0\n" << endl;
			else
			{
				cout << n << ' ';
				for(int j = 0 ; j < n ;j++)
				{
					if(j != n -1) cout << AdjList[i][j].first+1 << ' ';
					else cout << AdjList[i][j].first+1 << endl;
				}
				for(int j = 0 ; j < n ;j++)
				{
					if(j != n -1) cout << AdjList[i][j].second << ' ' ;
					else cout << AdjList[i][j].second << endl;
				}
			}
		}
	}
		
	return 0;

}