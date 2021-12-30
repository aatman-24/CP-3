#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


void display(vector<pair<int,int>> &ele)
{
	int m = ele.size();
	for(double i = 0 ; i < m; i++)
	{
		cout << ele[i].first << '-' << ele[i].second << ' ';
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


	// #prerequisite

	map<char,char> mapper;

	vector<pair<char,char>> brackets = {{')','('},{']','['},{'}','{'}};

	for (int i = 0; i < 3 ; i++)
	{
		mapper[brackets[i].first] = brackets[i].second;
	}



	int t; cin >> t;
	string s;
	while(t--)
	{
		stack<char> st;
		
		cin >> s;


		for(double i = 0 ; i < s.size() ; i++)
		{
			if(mapper.find(s[i]) != mapper.end())
			{
				if(st.top() == mapper[s[i]])
				{
					st.pop();
				}
				else
				{
					cout << "No" << endl;
					break;
				}
			}
			else
			{
				st.push(s[i]);
			}
		}

		if(st.empty()) cout << "Yes" << endl;
	}



	
}