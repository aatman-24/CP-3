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


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	int t; cin >> t;
	while(t--)
	{
		std::vector <double> character_value(12800,0);
		int k; cin >> k;
		while(k--)
		{
			char ch;
			int value_of_ch;
			cin >> ch >> value_of_ch;
			character_value[int(ch)] = value_of_ch;
		}
		int m; cin >> m;
		long long int total_cent = 0;
		string s;
		getline(cin,s);
		while(m--)
		{
			getline(cin,s);
			// cout << s << endl;
			for(int i = 0;i < int(s.size());i++)
			{
				int value;
				if (s[i] == ' ' || (s[i] > 128)) value = 0;
				else value = character_value[int(s[i])];
				total_cent += value;
			}
		}
		double dollar = total_cent * (0.01);
		printf("%3.2f$\n",dollar);
		character_value.clear();
	}
	
}	



