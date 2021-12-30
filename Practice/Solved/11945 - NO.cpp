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

	int data_set;
	std::vector<double> mean_store;
	while (cin >> data_set)
	{
		int month = 12;
		std::vector<double> store;
		while (month--)
		{
			double p_m;
			cin >> p_m;
			store.push_back(p_m);
		}
		double total = 0;
		for (double i = 0;i < store.size() ; i++)
		{
			total += store.at(i);
		}
		double mean = total / 12;
		mean_store.push_back(mean);
	}
	for (double i = 0 ; i < mean_store.size() ; i++)
	{
		cout << i+1 << " $" << mean_store.at(i) << endl;
	}
	
}	



