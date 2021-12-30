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
typedef pair<ii,string> ppiis;
typedef vector<ppiis> vppiis;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


bool sort_fun(ppiis a, ppiis b)
{
	if(a.first.first < b.first.first) return true;
	if((a.first.first == b.first.first) && (a.first.second < b.first.second)) return true;
	return false;
}



void display(vppiis &arr)
{
	for(double i = 0; i < arr.size() ;i++)
	{
		cout << arr[i].second << ' ' << arr[i].first.first << ' ' << arr[i].first.second << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	
	int n_data,l_price,h_price,q_n,p;
	string m_name;

	int t; cin >> t;
	vppiis record;

	while(t--)
	{
		record.clear();
		cin >> n_data;
		int n_temp_data = n_data;
		while(n_temp_data--)
		{
			cin >> m_name >> l_price >> h_price;
			record.push_back({{l_price,h_price},m_name});
		}

		sort(record.begin(),record.end(),sort_fun);

		cin >> q_n;
		while(q_n--)
		{
			cin >> p;

			int c = 0;
			string name;
			for(int i = 0 ; i < n_data; i++)
			{
				if(record[i].first.first > p) break;
				if(p > record[i].first.second) continue;
				if((record[i].first.first <= p) && (p <= record[i].first.second))
				{
					name = record[i].second;
					c++;
				}
			}
			if(c == 1) cout << name << endl;
			else cout << "UNDETERMINED" << endl;

		}




		if(t != 0) cout << endl;
	}



	return 0;
}