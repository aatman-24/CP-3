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

	// Prerequisite.
	std::vector<double> weight;
	weight.assign(100,0);
	std::vector<char> v = {'W','H','Q','E','S','T','X'};
	std::vector<double> value = {1,1/2.0,1/4.0,1/8.0,1/16.0,1/32.0,1/64.0};
	int i = 0;
	for (char n : v)
	{
		weight[int(n)] = value.at(i);
		i++;	
	}

	
	string s;
	while(cin >> s)
	{
		if (s == "*") break;
		int n = s.length();
		double sum;
		int count = 0;
		for (double i  = 0 ; i < n ; i++)
		{
			if (s[i] == '/')
			{	
				if (sum == 1.0) count++;
				sum = 0;
			}
			else sum += (weight.at(int(s[i])));
		}
		cout << count << endl;
	}
}	



