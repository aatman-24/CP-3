#include <bits/stdc++.h>
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long


using namespace std;


void display(vector<string> temp)
{
	for(double i = 0 ; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';
	}
	cout << endl;
}

int a,b;

void do_all(map<string,int> &mss,map<string,pair<string,string>> &son,string &name)
{
		if(mss.end() == mss.find(name))
		{
			string first = son[name].first;
			string second = son[name].second;
			if(mss.end() == mss.find(first))
			{
				do_all(mss,son,first);
			}
			else a = mss[first];
			if(mss.end() == mss.find(second))
			{
				do_all(mss,son,second);
			}
			else b = mss[second];
			if((a == 0 && b == 0) || (a+b == -1))
			{
				mss[name] = 0;
			}
			else if(((a+b) < -1) || (a + b == 1))
			{
				mss[name] = -1;
			}
			else
			{
				mss[name] = 1;
			}
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

	std::vector<string> decode = {"recessive","non-existent","dominant"};
	map<string,int> mss;
	map<string,pair<string,string>> son;
	vector<string> all_name;

	string first,second,name;

	int value;
	int t; cin >> t;
	while(t--)
	{
		cin >> first >> second;
		if(second == "dominant" || second == "recessive" || second == "non-existent")
		{
			if(second == "dominant") value = 1;
			else if (second == "recessive") value = -1;
			else value = 0;

			mss.insert({first,value});
			all_name.push_back(first);
		}
		else
		{
			if(son.end() == son.find(second))
			{
				son[second].first = first;
				all_name.push_back(second);
			}
			else
			{
				son[second].second = first;
			}
			
		}
	}

	

	for(double i = 0 ; i < all_name.size() ;i++)
	{
		name = all_name[i];
		if(mss.end() == mss.find(name))
		{
			do_all(mss,son,name);
		}
	}

	sort(all_name.begin(),all_name.end());
	for(double i = 0 ; i < all_name.size() ;i++)
	{
		name = all_name[i];

			cout << name << ' ' << decode[mss[name]+1] << endl;
	}


	return 0;
	
}	



