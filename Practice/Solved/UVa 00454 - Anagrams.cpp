#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
	}
}


void store(std::vector<int> a,std::vector<string> v,std::vector<string> &result) 
{ 
	string s = " ";
    for (int i = 0; i < int(a.size()); i++) { 
		s += v.at(a.at(i));        
    } 
    result.push_back(s);
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int t;
	cin >> t;
	while (t--)
	{
		std::vector<string> store;
		std::vector<string> updated_store;
		while(cin)
		{
			string s;
			getline(cin,s);
			store.push_back(s);
		}
		for (double i = 0; i < store.size(); i++) 
		{ 
			string temp = " ";
			string l = store.at(i);
			for (double j = 0 ; j < l.size() ; j++)
			{
				if (l.at(j) != ' ')
				{
					temp += l.at(j);
				}
			}
			sort(temp.begin(),temp.end());

			if (temp != " ") updated_store.push_back(temp);
    	}
		for (double i = 0;i < updated_store.size();i++)
		{
			for (double k = i;k < updated_store.size() ;k++)
			{
				if ((i != k) && (updated_store[i] == updated_store[k]))
				{
					cout << store.at(i) << " = " << store.at(k) << '\n';
				}
			}
		}
	}
}

