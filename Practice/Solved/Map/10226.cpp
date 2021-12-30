#include <bits/stdc++.h>
#include <iostream>
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


	int t; cin >> t;
	string temp,s;
	getline(cin,s);
	getline(cin,s);
	map<string,double> msi;
	int count;
	while(t--)
	{
		count = 1;
		while(getline(cin,s))
		{
			cin >> temp;
			if(msi.find(temp) == msi.end())
			{
				msi[temp] = 1;
			}
			else
			{
				msi[temp] += 1;
			}
			count ++;
		}

		std::cout.precision(6);
		for(auto it:msi)
		{
			cout << it.first << ' ' << it.second/count * 100 << endl;
		}

		msi.clear();


	}



	return 0;
	
}	



