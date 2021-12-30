#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
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


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	map<string,int> m;
	vector<string> all_str;
	
	string temp;
	int count = 1,set = 0;
	string abc = "abcdefghijklmnopqrstuvwxyz";


	for(int i = 0 ; i < 26;i++)
	{
		temp = "";
		temp += abc[i];
		m.insert({temp,count});
		all_str.push_back(temp);
		count++;
	}

	int i = 0;
	temp = all_str[0];
	while(true)
	{
		int x = int(temp[temp.size()-1]);
		for(int k = x+1; k < 123 ; k++)
		{
			temp = all_str[i];
			temp += char(k);
			m.insert({temp,count});
			if(temp.size() == 6)
			{
				set = 1;
				break;
			}
			all_str.push_back(temp);
			count++;
		}
		if(set) break;
		i++;
		temp = all_str[i];

	}

	string s;
	while(getline(cin,s))
	{
		if(s =="") break;
		temp = s;
		sort(temp.begin(),temp.end());
		if(temp != s)
		{
			cout << '0' << endl;
		}
		else
		{
			cout << m[s] << endl;	
		}
	}

	return 0;
	
}	



